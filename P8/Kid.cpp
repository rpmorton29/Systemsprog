//
//  Kid.cpp
//  P8
//
//  Created by Ryan Morton on 4/23/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//

#include "Kid.hpp"


static void handler(int hand){
    
    return;
}

Kid::Kid(Model* mo,int IDNUM){///Linker is from here
    m = mo;
    sigemptyset(&set);
    sigaddset(&set, SIGQUIT);
    sigaddset(&set, SIGUSR1);
    sigaddset(&set, SIGUSR2);
    signal(SIGUSR1,handler);
    signal(SIGUSR2,handler);
    signal(SIGQUIT,NULL);
    pthread_attr_t  attr;
    pthread_attr_init(&attr);
  
    pthread_create( &tid, NULL, startThread, (void*) this );
    id=IDNUM;
    seatnum= -1;
    
    
}

//============================================================================

//============================================================================

void Kid::Play(){
    int temp;
    for(;;){
        sigwait(&set,&temp);
        if(SIGUSR2==temp){DoSit();}
        else if(SIGUSR1==temp){ StandUp();}
        else{pthread_exit(NULL);}
   
        
    }
}
//============================================================================
int Kid::Getid(){
    
    return id;
    
}
pthread_t Kid::GetTid(){
    return tid;
}
//============================================================================

 void* startThread(void* kid) {
    
     Kid* k = (Kid*) kid;
    k->Play();
    return NULL;
}

//============================================================================
void Kid::StandUp(){
    m->chairs[seatnum] = -1;
    seatnum =-1;
}
//============================================================================
void Kid::DoMarch(){
    usleep(10000);
    m->nMarching++;
}
void Kid::DoSit(){
    pthread_mutex_lock(&m->mx);
    
    for(int i= 0; i<m->nChairs+1;i++){
        //cout<<"child: "<<id<< " Attempting to sit: "<<endl;
        if(m->chairs[seatnum]==-1){
            m->chairs[seatnum]= id;
            break;
        }
        else {
            seatnum++;
            if(seatnum == m->nChairs){
                seatnum=-1;
                
            }
        }
        
    }
    cout<<" "<<endl;
   
    pthread_mutex_unlock(&m->mx);
}
//============================================================================
ostream& Kid::print(ostream &out){
 out<<"Child: "<<id<<" Tid: "<<tid<<endl;
    return out;
}
//============================================================================
void Kid::quit(){
    
    pthread_exit(tid);

}
//============================================================================
bool Kid::IsSitting(){
    
   
    if ( seatnum==-1){
        
        return false;
    }
    else{
        return true ;
    }
}
