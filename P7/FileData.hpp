//
//  FileData.hpp
//  P7
//
//  Created by Ryan Morton on 4/15/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//

#ifndef FileData_hpp
#define FileData_hpp

#include <stdio.h>
#include "Params.hpp"
class FileData{
    
public:
    FileData() {}
    FileData(dirent *dir,struct stat &info);
    ~FileData()=default;
    bool operator<(const FileData f)const;
    bool operator== (const FileData f)const;
    ostream& print(ostream& out);
    string pathname;
    unsigned long int inode;
    long long filesize;
    unsigned char sha256[CC_SHA256_DIGEST_LENGTH];
    string filename;
    char cwd[256];
    string filetype;
    bool isDirectory() const;
private:
    void FingerPrint();
    CC_SHA256_CTX ctx;
    #define BUFSIZE 4096
    

};
inline ostream& operator<<(ostream& out,FileData f){return f.print(out);}
#endif /* FileData_hpp */
