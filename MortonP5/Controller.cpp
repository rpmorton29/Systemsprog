//
//  Controller.cpp
//  P5
//
//  Created by Ryan Morton on 3/3/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//

#include "Controller.hpp"

Controller::Controller(int argc, char* const* argv){
    p = Params(argc,argv);
    ck = p.dir;
    CheckDir();
    dir = opendir(ck);
    CtDir = ck;
    ProccessDir();
}
//==================================================================
void Controller::CheckDir(){
    status = lstat(ck, &info);
    if(!ck){
        fatal("Not a Directory\n");
        return;
    }
}
//==================================================================
void Controller::ProccessDir(){
    while((CrntDir = readdir(dir))!= NULL){
        if(p.all== false){
            if(CrntDir->d_name[0] !='.'){
                files.push_back(string(CrntDir->d_name));// pathname
            }
        }
        else{ files.push_back(string(CrntDir->d_name));
        }
    }
    closedir(dir);
    sort(files.begin(), files.end());
    if(p.O==false){
        for (int i = 0; i < files.size(); i++) {
            if(p.Verb==false){
                
                cout << files[i] << endl;
            }
            else{
                cout <<string(ck)<< files[i]<< endl;
            }
        }
    }
    else{
        outf.open(p.Filename);
        for (int i = 0; i < files.size(); i++) {
            if(p.Verb==false){
                outf << files[i] << endl;
            }
            else{
                outf<<string(ck)<< files[i]<< endl;
            }
        }
        outf.close();
    }
}


