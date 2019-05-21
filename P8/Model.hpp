//
//  Model.hpp
//  P8
//
//  Created by Ryan Morton on 4/23/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//

#ifndef Model_hpp
#define Model_hpp

#include <stdio.h>
#include "tools.hpp"
#include <mutex>
using namespace std;


class Model{
public:
    pthread_mutex_t mx = PTHREAD_MUTEX_INITIALIZER;
    int nChairs;
    int *chairs;
    int nMarching;
    pthread_cond_t cv = PTHREAD_COND_INITIALIZER;
    pthread_cond_t cv2 = PTHREAD_COND_INITIALIZER;
    Model(int nkids);
    Model()= default;
    ~Model()=default;
    
    
};

#endif /* Model_hpp */
