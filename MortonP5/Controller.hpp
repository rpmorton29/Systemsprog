//
//  Controller.hpp
//  P5
//
//  Created by Ryan Morton on 3/3/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <stdio.h>
#include "Params.hpp"



class Controller{
    
private:
    Params p ;
    ofstream outf;
    vector<string> files;
    DIR *dir;
    struct stat  info;
    string CtDir;
    struct dirent *CrntDir;
    int status;
    char *ck;
    
public:
    Controller(int argc, char* const* argv);
    void CheckDir();
    void ProccessDir();
    
    
    
    
    
};




#endif /* Controller_hpp */
