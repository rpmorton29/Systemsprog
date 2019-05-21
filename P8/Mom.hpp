//  bvcbnvj
//  Mom.hpp
//  P8
//
//  Created by Ryan Morton on 4/23/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//

#ifndef Mom_hpp
#define Mom_hpp

#include <stdio.h>
#include "Kid.hpp"
#include "Model.hpp"

class Mom{
public:
    Model m;
    Kid kid;
    void PlayoneRound(Model* m,int nkids);
    Mom(int nkids);
    vector<Kid*> players;
    void PrintPlayers();
    int stillin;
};



#endif /* Mom_hpp */
