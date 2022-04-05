#include "PGMimageProcessor.h"
#include <memory>
#include <fstream>
#include <sstream>
#include <queue>

//default constructor
PKNNIV001::PGMimageProcessor::PGMimageProcessor(std::string n):
    name{n}{

        //read through header of file
        std::string line{""};
        std::string size{""};
        std::stringstream header{line};
        std::ifstream file{n, std::ios::binary};
        
        //reading through header-----------
        while(true){
            std::getline(file,line);
            header << line << std::endl;
            if(line == "255"){
                break;
            }
            size= line;
        }
        std::stringstream ssize{size};
        ssize >> size;
        width=std::stoi(size);
        ssize >> size;
        height =std::stoi(size);
        //--------------------------------

        file.seekg(0,file.end);
        int length = header.str().length();
        std::streampos linewidth{width};
        //std::streampos h{length};
        //std::streampos si = file.tellg()-h;
        file.seekg(int(header.str().length())+1, std::ios::beg);

        //read file in line by line into unique pointer array
        for(size_t i = 0; i<height;++i){
            file.getline(image[i].get(),linewidth);
        }
        
        //close file
        file.close();
    }

//copy constructor
PKNNIV001::PGMimageProcessor::PGMimageProcessor(const PGMimageProcessor &rhs):
    PGMimageProcessor{rhs.name}{}//create copy of unique pointer array

//move constructor
PKNNIV001::PGMimageProcessor::PGMimageProcessor(PGMimageProcessor &&rhs):
    name{rhs.name}{}//transfer ownership of unique pointer

//copy assignment
PKNNIV001::PGMimageProcessor &PKNNIV001::PGMimageProcessor::operator=(const PGMimageProcessor &rhs){
    name = rhs.name;//create new instance of image array
    return *this;
}

//move assignment
PKNNIV001::PGMimageProcessor &PKNNIV001::PGMimageProcessor::operator=(PGMimageProcessor &&rhs){
    name = rhs.name;//transfer ownership of unique pointer
    return *this;
}

//destructor
PKNNIV001::PGMimageProcessor::~PGMimageProcessor(){
    //delete memory from read in image
}


/* process the input image to extract all the connected components,
based on the supplied threshold (0...255) and excluding any components
of less than the minValidSize. The final number of components that
you store in your container (after discarding undersized one)
must be returned.*/
int PKNNIV001::PGMimageProcessor::extractComponents(unsigned char threshold, int minValidSize){
    //image now in memory, now have to extract components
    
    std::queue<std::pair<int,int>> q;   //queue storing all pixels in a component

    int ID{0};  //iteratng count of number of components also the current index of component in component vector

    //loop over each pixel in input image
    for(size_t i=0; i<height;++i){
        for(size_t j = 0; j<width;++i){
            //if above threshold, add to queue
            if(image[i][j] >=threshold){
                //create new component
                components.push_back(ConnectedComponent(ID));
                //add current pixel to it
                components[ID].addPixel(i,j);
                //make current pixelk = 0
                image[i][j] = '\0';
                //increment number of pixels
                components[ID].incPixels();
                
                //check if NSEW pixel is valid and add pixels to queue
                if(0<=i+1<=height){  //south pixel
                    q.push(std::make_pair(i+1,j));
                }
                if(0<=i-1<=height){ //north pixel
                    q.push(std::make_pair(i-1,j));
                }
                if(0<=j+1<=width){  //east pixel
                    q.push(std::make_pair(i,j+1));
                }
                if(0<=j-1<=width){  //west pixel
                    q.push(std::make_pair(i,j-1));
                }
                
                //while queue not empty - continue breadth first search
                while(!q.empty()){
                    //check if front of queue is greater than threshold
                    if(image[q.front().first][q.front().second] >= threshold){
                        //add to component and turn to 0
                        components[ID].addPixel(q.front().first,q.front().second);
                        image[q.front().first][q.front().second] = '\0';
                        components[ID].incPixels();

                        //only if current pixel is valid do we check surounding pixels
                        //now check if NSEW of front is valid then add to queue
                        if(0<=q.front().first+1<=height){  //south pixel
                        q.push(std::make_pair(q.front().first+1,q.front().second));
                        }
                        if(0<=q.front().first-1<=height){  //north pixel
                            q.push(std::make_pair(q.front().first-1,q.front().second));
                        }
                        if(0<=q.front().second+1<=width){  //east pixel
                            q.push(std::make_pair(q.front().first,q.front().second+1));
                        }
                        if(0<=q.front().second-1<=width){  //west pixel
                            q.push(std::make_pair(q.front().first,q.front().second-1));
                        }
                    }
                    //pop front off of queue
                    q.pop();
                }
            }
        }
    }
    //return number of components
    return components.size();
}

/* iterate - with an iterator - though your container of connected
components and filter out (remove) all the components which do not
obey the size criteria pass as arguments. The number remaining
after this operation should be returned.*/
int PKNNIV001::PGMimageProcessor::filterComponentsBySize(int minSize, int maxSize){

    //iterator to iterate over vector of ConnectedComponents
    std::vector<ConnectedComponent>::iterator i;
    for(i=components.begin();i!=components.end();++i){
        //check if it violates size criteria
        if(i.base()->getNoPixels()<minSize || i.base()->getNoPixels()>maxSize){
            i = components.erase(i);
        }
    }

    //return new size of vector
    return components.size();

}

/* create a new PGM file which contains all current components
(255=component pixel, 0 otherwise) and write this to outFileName as a
valid PGM. the return value indicates success of operation*/
bool PKNNIV001::PGMimageProcessor::writeComponents(const std::string & outFileName){}
// return number of components
int PKNNIV001::PGMimageProcessor::getComponentCount(void) const{}

// return number of pixels in largest component
int PKNNIV001::PGMimageProcessor::getLargestSize(void) const{}
// return number of pixels in smallest component
int PKNNIV001::PGMimageProcessor::getSmallestSize(void) const{}
/* print the data for a component to std::cout
see ConnectedComponent class;
print out to std::cout: component ID, number of pixels*/
void PKNNIV001::PGMimageProcessor::printComponentData(const PKNNIV001::ConnectedComponent & theComponent) const{}