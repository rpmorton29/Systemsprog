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
#include "FileData.hpp"


class Controller{
    
private:
    Params p ;
    ofstream outf;
    vector<string> files;
    vector<FileData> Tree1;
    vector<FileData> Tree2;
    vector<FileData> Dirholder1;
    vector<FileData> Dirholder2;
    string ftype;
    unsigned int fingerprint;
    DIR *dir;
    DIR *dir2;
    struct stat  info;
    struct stat  info2;
    struct dirent *CrntDir;
    int status;
    int status2;
    int Dircount;
    int Tree1count;
    int Tree2count;
    char *ck;
    char *ck2;
    char cwd[256];
    CC_SHA256_CTX ctx;   // A structure of state info used in computing SHA256.
    string path;
    //string temp;
    void DoLevel();
    void cmtRecursion();
    
#define BUFSIZE 4096
    
public:
    Controller(int argc, char* const* argv);
    void CheckDir();
    int OneDir(string chdr,vector<FileData> &temp);
    void Travel(string chdr);
    void CheckType();
    void GetSize();
    void GetCrntDir();
    void Dolevel();
    void cmt();
    int cmtDir(string chdr, vector<FileData> &vec);
    void travel(string chdr,vector<FileData> &vec);
    
    
};




#endif /* Controller_hpp */
