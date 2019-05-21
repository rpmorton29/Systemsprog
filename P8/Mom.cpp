//
//  Mom.cpp
//  P8
//
//  Created by Ryan Morton on 4/23/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//

#include "Mom.hpp"
Mom::Mom(int nkids){
    m = Model(nkids);
    
    for(int i=0; i<nkids; i++){
        players.push_back(new Kid(&m, i));
        usleep(10000);
    }
    stillin = nkids;
    for(int x=0;x<nkids-1;x++){
   PlayoneRound(&m,nkids);
        cout<<"NUMBER OF PLAYERS:"<<stillin<<endl;
    }
    if(stillin==1){
        cout<<"Winner is Player: "<<players[0]->id<<endl;
    }
}
//==============================================================================
void Mom::PrintPlayers(){
   
    for(Kid* kid : players){
        cout<<"Child: "<<kid->Getid()<<endl;
    }
}
//==============================================================================
void Mom::PlayoneRound(Model* m,int nkids){
    
    cout<<"=================ROUND===============\n";
    for(int i=0; i<m->nChairs; i++){
        m->chairs[i]=-1;
    }
        
    for(int i=0; i<stillin; i++){
        
        pthread_kill(players[i]->tid, SIGUSR2);
        
        
        
    }
    
    usleep(1000);
    
    for(int i=0; i<stillin; i++){
        cout<<"Child: "<<players[i]->id<<" SITTING "<<players[i]->IsSitting()<<endl;
        cout<<"Sitting at: "<<m->chairs[players[i]->seatnum]<<endl;
        
        if(!players[i]->IsSitting()){
            swap(players[i],players[nkids-1]);
            cout<<"Player:  "<<players[nkids-1]->id<<" KIllED"<<endl;
            
            pthread_kill(players[nkids-1]->tid, SIGQUIT);
            pthread_join(players[nkids-1]->tid,NULL);
        
            players.pop_back();
        }
        
        
         }
   
         usleep(10000);
    for(int i=0; i<stillin; i++){
        
        pthread_kill(players[i]->tid, SIGUSR1);
        
    }
     usleep(10000);
        stillin--;
        m->nChairs--;
        m->chairs--;
        
    
    //}
}
//==============================================================================

