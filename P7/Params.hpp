//
//  Params.hpp
//  P6
//
//  Created by Ryan Morton on 3/20/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//

#ifndef Params_hpp
#define Params_hpp

#include <getopt.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <CommonCrypto/CommonDigest.h>
#include <string.h>
#include <vector>
#include "tools.hpp"



using namespace std;
class Params{
    
private:
    char *Filename;
    bool all=false,R=false,Verb=false,O = false ,Help = false;
    char *dir;
    char *dir2;
    int code;
    void outputLong( const char* str, const char* ag );
    void usage();
    friend class Controller;
    
public:
    Params(int argc, char* const* argv);
    Params() {}
    void PrintBools();
    void print();
};

#endif /* Params_hpp */
