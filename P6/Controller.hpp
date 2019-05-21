//
//  Controller.hpp
//  P6
//
//  Created by Ryan Morton on 3/20/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include "Params.hpp"



class Controller{
    
private:
    Params p ;
    ofstream outf;
    vector<string> files;
    string ftype;
    unsigned int hash;
    DIR *dir;
    struct stat  info;
    string CtDir;
    struct dirent *CrntDir;
    int status;
    char *ck;
    char cwd[256];
    CC_SHA256_CTX ctx;   // A structure of state info used in computing SHA256.
    string path;
    string temp;
    #define BUFSIZE 4096 
    
public:
    Controller(int argc, char* const* argv);
    void CheckDir();
    void ProccessDir(string chdr);
    void Travel(string chdr);
    void CheckType();
    void GetSize();
    void GetCrntDir();
    void PrintSHA(string file);
    
    
    
};




#endif /* Controller_hpp */
