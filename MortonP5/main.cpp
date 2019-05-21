//
//  main.cpp
//  P5
//
//  Created by Ryan Morton on 2/27/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//


#include "Controller.hpp"
#include "tools.hpp"
int main(int argc, char* argv[]) {
    banner();
    Controller c = Controller(argc, argv);
    bye();
    return 0;
}
