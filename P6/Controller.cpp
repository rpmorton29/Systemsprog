//
//  Controller.cpp
//  P6
//
//  Created by Ryan Morton on 3/20/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//

#include "Controller.hpp"


Controller::Controller(int argc, char* const* argv){
    p = Params(argc,argv);
    ck = p.dir;
    CheckDir();
    dir = opendir(ck);
    CtDir = ck;
    if (p.O==true){
        outf.open(p.Filename);
    }
    if (p.R==true){
        Travel(string(ck));
    }
    else{
        ProccessDir(string(ck));
    }
    outf.close();
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
void Controller::ProccessDir(string chdr){
    chdir(chdr.c_str());
    
    getcwd(cwd,sizeof(cwd));
    
    string path;
    dirent *Curdir = nullptr;
    DIR * dirptr=opendir(cwd);
    
    while((Curdir = readdir(dirptr))){
        string temp = cwd;
        path = temp+'/'+ Curdir->d_name;
        
        lstat(path.c_str(), &info);
        if((strcmp(Curdir->d_name, ".")==0)||(strcmp(Curdir->d_name, "..")==0)) {continue;}
        if(p.all== false){
            if((Curdir->d_name[0] !='.')){
                if (p.O == false){
                    if (p.Verb==true){
                        cout<<path<<" ";
                    }
                    else{
                        cout<<Curdir->d_name<<" ";
                    }
                }
                else{
                    if (p.Verb==true){
                        outf<<path<<" ";
                    }
                    else{
                        outf<<Curdir->d_name<<" ";
                    }
                    
                }
                
            }
        }
        else{
            if (p.Verb==true){
                cout<<path<<" ";
            }
            else{
                cout<<Curdir->d_name<<" ";
            }
        }
        
        
        CheckType();
        if (S_ISDIR(info.st_mode)){
            
            ftype = "Type: DIrectory";
            files.push_back(string(Curdir->d_name)+" "+ftype);
            
            
            continue;
        }
        else if (S_ISREG(info.st_mode)){
            PrintSHA(string(Curdir->d_name));
            
        }
        if(p.all== false){
            if((Curdir->d_name[0] !='.')){
                files.push_back(string(Curdir->d_name)+" "+ftype);// pathname
            }
        }
        else{ files.push_back(string(Curdir->d_name));
        }
    }
    chdir("..");
    closedir(dirptr);
}
//=====================================================================
void Controller::CheckType(){
    
    getcwd(cwd,sizeof(cwd));
    if (S_ISREG(info.st_mode)){
        ftype = "Type: Regular file ";
        
    }
    else if (S_ISDIR(info.st_mode)){
        ftype = "Type: Directory\n";
        
    }
    else if (S_ISCHR(info.st_mode)){
        ftype = "Type: Special Character ";
    }
    else if (S_ISBLK(info.st_mode)){
        ftype = "Type: Block File ";
    }
    else if (S_ISFIFO(info.st_mode)){
        ftype = "Type: Pipe ";
    }
    else if (S_ISLNK(info.st_mode)){
        
        ftype = "Type: Symbolic Link\n";
    }
    else if (S_ISSOCK(info.st_mode)){
        ftype = "Type: Socket ";
    }
    if (p.O==false){
        cout<<ftype;
    }
    else{
        outf<<ftype;
    }
    
}
//=====================================================================
void Controller::Travel(string chdr){
    chdir(chdr.c_str());
    
    getcwd(cwd,sizeof(cwd));
    
    string path;
    dirent *Curdir = nullptr;
    DIR * dirptr=opendir(cwd);
    
    while((Curdir = readdir(dirptr))){
        
        string temp = cwd;
        
        path = temp+'/'+ Curdir->d_name;
        lstat(path.c_str(), &info);
        if((strcmp(Curdir->d_name, ".")==0)||(strcmp(Curdir->d_name, "..")==0)) {continue;}
        if(p.all== false){
            if((Curdir->d_name[0] !='.')){
                if (p.O == false){
                    if (p.Verb==true){
                        cout<<path<<" ";
                    }
                    else{
                        cout<<Curdir->d_name<<" ";
                    }
                }
                else{
                    if (p.Verb==true){
                        outf<<path<<" ";
                    }
                    else{
                        outf<<Curdir->d_name<<" ";
                    }
                    
                }
                
            }
        }
        else{
            if (p.Verb==true){
                cout<<path<<" ";
            }
            else{
                cout<<Curdir->d_name<<" ";
            }
        }
        CheckType();
        if (S_ISDIR(info.st_mode)){
            
            
            if(S_IXUSR&info.st_mode){
                Travel(string(Curdir->d_name));
            }
        }
        else if (S_ISREG(info.st_mode)){
            PrintSHA(string(Curdir->d_name));
            
        }
        
        
        
        if(p.all== false){
            if((Curdir->d_name[0] !='.')){
                files.push_back(string(Curdir->d_name)+" "+ftype);// pathname
            }
        }
        else{ files.push_back(string(Curdir->d_name));
        }
        
    }
    chdir("..");
    closedir(dirptr);
}
void Controller::PrintSHA(string filename){
    
    ifstream in (filename);
    if (!CC_SHA256_Init(&ctx)) fatal("SHA256_Init failure");
    char buf[BUFSIZE];
    
    for (;;) {
        in.read( buf, BUFSIZE );
        size_t bytes_read = in.gcount();
        if (bytes_read == 0) break;
        // Update the state by processing the next block of data.
        if (!CC_SHA256_Update( &ctx, buf, bytes_read) ) fatal("SHA256_Update failure");
    }
    unsigned char md[CC_SHA256_DIGEST_LENGTH];
    // Terminate SHA256 algorithm and extract the answer from the context.
    if (!CC_SHA256_Final(md, &ctx)) fatal("SHA256_Final failure");
    if (p.O==false){
        cout <<"The SHA256 Fingerprint is: ";
        for (int k=0; k<CC_SHA256_DIGEST_LENGTH; k++) {
            cout <<hex <<setfill('0') <<setw(2) <<(int)md[k];
        }
        cout <<"\n" <<dec;
    }
    else{
        outf <<"The SHA256 Fingerprint is: ";
        for (int k=0; k<CC_SHA256_DIGEST_LENGTH; k++) {
            outf <<hex <<setfill('0') <<setw(2) <<(int)md[k];
        }
        outf <<"\n" <<dec;
    }
    
    
    
}
