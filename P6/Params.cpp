//
//  Params.cpp
//  P6
//
//  Created by Ryan Morton on 3/20/19.
//  Copyright © 2019 Ryan Morton. All rights reserved.
//

#include "Params.hpp"
Params::Params(int argc, char* const* argv){
    struct option longOpts[] = {
        { "verbose",    no_argument,       NULL,  'v' },
        { "out",        required_argument, NULL,  'o' },
        { "help",  no_argument,       NULL,  0 },
        { "Recursive",  no_argument,       NULL,  'R' },
        { NULL,         0,                 NULL,   0  }
    };
    int ch = 0;
    for (;;) {                      // Process the command-line switches
        ch = getopt_long(argc, argv, ":vRiaho",longOpts,&code);
        if( ch == -1 ) break;
        switch (ch) {
            case 'v':    Verb=true;break;
            case 'R':    R=true;break;
            case 'a':    all=true;break;
            case 'o':    O=true;Filename = argv[optind]; break;
            case 0:    {
                outputLong(longOpts[code].name, optarg);
                break;
            }
            default:     usage(); Help=true; break;
        }
    }
    
    dir=argv[optind];
    
}
//==================================================================
//Params::Params(){}
//==================================================================
void Params::print(){
    cout<<"VERB "<<Verb<<" hidde "<<all<<" recursive "<<R<<endl;
    if (Verb == true){cout<<"Verbose? Yes\n";}
    else{cout<<"Verbose? No\n";}
    if ( all == true){cout<<"Hidden Files? Yes\n";}
    else{cout<<"Hidden Files? No\n";}
    if (R==true){cout<<"Recursive? Yes\n";}
    else{cout<<"Recursive? No\n";}
    if (Help==true){cout<<"Help? Yes\n";}
    else{cout<<"Help? No\n";}
    if (O==true){cout<<"Output File: "<<Filename<<endl;
    }
}
//==================================================================
void Params::outputLong( const char* str, const char* ag ){
    
    if (strcmp(str, "Recursive")==0){
        R =true;
    }
    if(strcmp(str, "Verbose")==0){
        Verb =true;
    }
    if(strcmp(str,"help")==0){
        Help =true;
        usage();
    }
    if(strcmp(str,"Out")==0){
        O =true;
    }
}
//==================================================================
void Params::usage(){
    printf("Usage:  options [-aovr] [--recursive] [--verbose] \n"
           "\t\t [--out filename] \n");
}
//==================================================================
void Params::PrintBools(){
    cout<<"VERB "<<Verb<<" hidden "<<all<<" recursive "<<R<<endl;
}
