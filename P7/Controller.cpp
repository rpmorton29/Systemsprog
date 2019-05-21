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
    
    ck2 = p.dir2;
    
    CheckDir();
    dir = opendir(ck);
    dir2 = opendir(ck2);
    if (p.O==true){
        outf.open(p.Filename);
    }
    
    Dolevel();

   
    
    outf.close();
}
//==================================================================
void Controller::CheckDir(){
    status = lstat(ck, &info);
    status2 = lstat(ck, &info2);
    if(!ck) {
        fatal("Two Valid Directories Needed\n");
    }
    if (!ck2){
        fatal("Two Valid Directories Needed\n");
        return;
    }
}
//==================================================================
int Controller::OneDir(string chdr, vector<FileData> &vec){
    Dircount = 0;
    FileData file;
    
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
        file = FileData(Curdir,info);
        if(file.isDirectory()){
            Dircount++;
            
        }
        if(!(find(vec.begin(), vec.end(), file)!= vec.end())){
        vec.push_back(file);
        }
    }
   
    sort(vec.begin(),vec.end());
   
    
    

   
    closedir(dirptr);
    return Dircount;
}
//=====================================================================

//====================================================================
void Controller::Dolevel(){
    
    chdir(path.c_str());
    getcwd(cwd,sizeof(cwd));
    
    
    Tree1count += OneDir(string(ck),Tree1);
    Tree2count += OneDir(string(ck2),Tree2);
    
    for (int i =0; i <Tree1count;i++){
        
        Dirholder1.push_back(Tree1.back());
        Tree1.pop_back();
    }
    
    for (int i =0; i <Tree2count;i++){
        
        Dirholder2.push_back(Tree2.back());
        Tree2.pop_back();
    }
   
    
   
    
    for (FileData file : Dirholder1){
        if(!(find(Dirholder2.begin(), Dirholder2.end(), file) != Dirholder2.end())){
            
            cout<<"different: \t"<<file<<endl;
            
        }
    }
    for (FileData file : Dirholder2){
        if(!(find(Dirholder1.begin(), Dirholder1.end(), file) != Dirholder1.end())){
            
            cout<<"different: \t"<<file<<endl;
            
        }
        
        else {
            
            string temp = p.dir;
            path = temp+'/'+ file.filename;
           
            chdir(path.c_str());
            getcwd(cwd,sizeof(cwd));
           
            ck = cwd;
            ck2 = cwd;
           
            cout<<"Same:   \t"<<file<<endl;
            if(p.R==true){
            OneDir(ck, Tree1);
            OneDir(ck2, Tree2);
            Tree1count--;
            Tree2count--;
            }
        }
        if (Tree1count==0 || Tree2count==0){
            break;
        }
    }
    for (FileData file : Tree1){
        if(!(find(Tree2.begin(), Tree2.end(), file) != Tree2.end())){
            
            cout<<"Subtraction: \t"<<file<<endl;
            
        }
    }

    for (FileData file : Tree2){
        if(!(find(Tree1.begin(), Tree1.end(), file) != Tree1.end())){
            
            cout<<"Addition: \t"<<file<<endl;
        }
        
        else {
            cout<<"Same:    \t"<<file<<endl;
        }
        
        
    }
    
}

//============================================================================



