//
//  FileData.cpp
//  P7
//
//  Created by Ryan Morton on 4/15/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//

#include "FileData.hpp"

FileData::FileData(dirent *dir,struct stat &info){
    filename = dir->d_name;
    getcwd(cwd,sizeof(cwd));
    pathname = string(cwd)+"/"+filename;
    inode = info.st_ino;
    if(S_ISDIR(info.st_mode)){
        filetype = "Directory";
    }
    if(S_ISLNK(info.st_mode)){
        filetype = "Link    ";
    }
    if(S_ISREG(info.st_mode)){
        filetype = "Regular  ";
    }
    filesize = info.st_size;
    FingerPrint();
}
//==================================================================
bool FileData::operator<(const FileData f)const{
    
    if(isDirectory()&&!f.isDirectory()){
        return false;
    }
    else if(!isDirectory()&&f.isDirectory())
    {
        return true;
    }
    else
        return filename<f.filename;
    
    return true;
}
//=================================================================
ostream& FileData::print(ostream& out){
    
    out<<inode<<"\t"<<filetype<<"\t"<<filesize<<"\t"<<filename;
    return out;
}
bool FileData::isDirectory()const
{
    return strcmp(filetype.c_str(),"Directory")==0;
}
//=================================================================
bool FileData::operator==(const FileData f)const{
    
    if(filename==f.filename){
        if(filetype==f.filetype){
            if(filesize==f.filesize){
                
                
                if(memcmp(sha256,f.sha256,CC_SHA256_DIGEST_LENGTH)==0){
                    return true;
                }
            }
        }
    }
    
    else{
        return false;
    }
    return false;
}
//=================================================================
void FileData::FingerPrint(){
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
   
    // Terminate SHA256 algorithm and extract the answer from the context.
    if (!CC_SHA256_Final(sha256, &ctx)) fatal("SHA256_Final failure");
  
}
//=================================================================
 

    
    

