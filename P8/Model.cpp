//
//  Model.cpp
//  P8
//
//  Created by Ryan Morton on 4/23/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//

#include "Model.hpp"


Model::Model(int nkids){
    nChairs = nkids - 1;
    chairs = new int[nChairs];
    //cout<<chairs<<endl;
    
}

