//
//  main.cpp
//  P8
//
//  Created by Ryan Morton on 4/23/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//

#include <iostream>
#include "Mom.hpp"

int main(int argc, const char * argv[]) {
    int x = atoi(argv[1]);
    if(x<2){
       
        fatal("Enter more players\n");
    }
    banner();
    Mom Mom(x);
    bye();
    return 0;
}
