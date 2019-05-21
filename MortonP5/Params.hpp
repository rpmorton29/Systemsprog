//
//  Params.hpp
//  P5
//
//  Created by Ryan Morton on 2/27/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//
#ifndef Params_hpp
#define Params_hpp

#include <stdio.h>
#include <getopt.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include <vector>
#include "tools.hpp"



using namespace std;
class Params{
    
private:
    char *Filename;
    bool all=false,R=false,Verb=false,O = false ,Help = false;
    char *dir;
    int code;
    void outputLong( const char* str, const char* ag );
    void usage();
    friend class Controller;
    
public:
    Params(int argc, char* const* argv);
    Params();
    void PrintBools();
    void print();
};

#endif /* Params_hpp */
