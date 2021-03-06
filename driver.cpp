#include <iostream>
#include <string>
#include "PGMimageProcessor.h"
//public methods to manipulate/ouptut connected components
int main(int argc, char *argv[]){
    //construct single instance of PGMimageProcessor

    
    //checking that there are arguements    
    if(argc == 1){
        std::cout << "ARGUEMENTS MISSING: [options] <inputPGMfile>" << std::endl;
        return 1;
    }
    
    int min{3};                 //for -s
    int max = 0;                //for -s
    unsigned char threshold{128};//for -t
    bool printData{false};      //for -p
    std::string outfile;        //for -w

    //Reading input arguements--------------------
    for(size_t i=2; i<argc;++i){
        std::string s{argv[i]};
        if(s=="-s"){
            min = std::atoi(argv[i+1]);
            max = std::atoi(argv[i+2]);
        }
        else if(s=="-t"){
            threshold = static_cast<unsigned char>(*argv[i+1]);
        }
        else if(s=="-p"){
            printData = true;
        }
        else if(s=="-w"){
            outfile = argv[i+1];
        }
    }
    std::string name{argv[argc-1]};
    //-------------------------------------------
    
    //create instance of PGMimageProcessor
    PKNNIV001::PGMimageProcessor processor{name};
    processor.extractComponents(threshold,min);
    processor.filterComponentsBySize(min,max);
    processor.writeComponents(outfile);



    return 0;
}