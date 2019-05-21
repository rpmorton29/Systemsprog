//
//  Kid.hpp
//  P8
//
//  Created by Ryan Morton on 4/23/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//

#ifndef Kid_hpp
#define Kid_hpp

#include <stdio.h>
#include "Model.hpp"
#include <pthread.h>
#include <signal.h>
#include "Glob.hpp"
/*void* startthread(void* kid){
    Kid* k = (Kid*) kid;
    k->play();
    return NULL;
    
}*/
//static void handler(int hand);
 void* startThread(void* Kid);
class Kid{
private:
    
    
    //int wantseat;
  
    sigset_t set;
    //int sig;
public:
      int seatnum;
    int id;
    pthread_t tid;
    Kid() = default;
    Kid(Model* m, int IDNUM);
    Model* m;
    int Getid();
    pthread_t GetTid();
    bool IsSitting();
    void StandUp();
    void DoSit();
    void Play();
    void DoMarch();
    ostream& print(ostream& out);
    void quit();
    
};
inline ostream& operator<<(ostream& out,Kid kid){return kid.print(out);}
#endif /* Kid_hpp */
