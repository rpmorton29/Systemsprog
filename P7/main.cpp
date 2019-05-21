//
//  main.cpp
//  P6
//
//  Created by Ryan Morton on 3/20/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//

#include "Controller.hpp"

int main(int argc, char* argv[]) {
    banner();
    //Params(argc, argv);
    Controller c = Controller(argc, argv);
    bye();
    return 0;
}
