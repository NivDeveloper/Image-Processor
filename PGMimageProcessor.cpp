#include "PGMimageProcessor.h"
#include <memory>
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
#include <cstring>

PKNNIV001::PGMimageProcessor::PGMimageProcessor(std::string n, std::vector<ConnectedComponent> comp, int h, int w):
    name{n}, components{comp}, height{h}, width{w}{}

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
            //std::cout << line << std::endl;
            if(line == "255"){
                break;
            }
            size= line;
        }
        //image{std::malloc(height)};
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
        //create 1d smart pointer to add each line 
        std::unique_ptr<char []> li;
        image = std::make_unique<std::unique_ptr<char[]>[]>(height);
        for(size_t i = 0; i<height-1;++i){
            li = std::make_unique<char[]>(width);

            //for(size_t j = 0; j<width;++j){
                file.read(li.get(),width);
                //std::cout << li.get()<< std::endl;
            //}
            image[i]=std::move(li);
            
            
            //std::cout << *image[i].get() << std::endl;       
        //add line to image 
        }
        
        
        //close file
        file.close();
    }

//copy constructor
PKNNIV001::PGMimageProcessor::PGMimageProcessor(const PGMimageProcessor &rhs):
    PGMimageProcessor{rhs.name, rhs.components,rhs.height,rhs.width}{}//create copy of unique pointer array

//move constructor
PKNNIV001::PGMimageProcessor::PGMimageProcessor(PGMimageProcessor &&rhs):
    name{rhs.name}, components{rhs.components}, height{rhs.height}, width{rhs.width}{}//transfer ownership of unique pointer

//copy assignment
PKNNIV001::PGMimageProcessor &PKNNIV001::PGMimageProcessor::operator=(const PGMimageProcessor &rhs){
    name = rhs.name;//create new instance of image array
    components = rhs.components;
    width = rhs.width;
    height = rhs.height;
    return *this;
}

//move assignment
PKNNIV001::PGMimageProcessor &PKNNIV001::PGMimageProcessor::operator=(PGMimageProcessor &&rhs){
    name = rhs.name;//transfer ownership of unique pointer
    components = rhs.components;
    width = rhs.width;
    height = rhs.height;
    return *this;
}

//destructor
PKNNIV001::PGMimageProcessor::~PGMimageProcessor(){
    //delete memory from read in image
}


/* process the input image to extract all the conn                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               ected components,
based on the supplied threshold (0...255) and excluding any components
of less than the minValidSize. The final number of components that
you store in your container (after discarding undersized one)
must be returned.*/
int PKNNIV001::PGMimageProcessor::extractComponents(unsigned char threshold, int minValidSize){
    //image now in memory, now have to extract components
    
    int ID{0};  //iteratng count of number of components also the current index of component in component vector

    //loop over each pixel in input image
    
    for(size_t i=0; i<height;++i){
        for(size_t j = 0; j<width;++i){
            //if above threshold, add to queue
            if(image[i][j] >=threshold){
                
                //queue storing all pixels in a component
                std::queue<std::pair<int,int>> q;
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
    }std::cout << "hello" << std::endl;
    //return number of components
    return components.size();
}

/* iterate - with an iterator - though your container of connected
components and filter out (remove) all the components which do not
obey the size criteria pass as arguments. The number remaining
after this operation should be returned.*/
int PKNNIV001::PGMimageProcessor::filterComponentsBySize(int minSize, int maxSize){

    if(maxSize == 0){
        maxSize = width*height;
    }

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
bool PKNNIV001::PGMimageProcessor::writeComponents(const std::string & outFileName){

    //output file
    std::ofstream ofile{outFileName, std::ios::binary};
    //if file didnt open, return false
    if(!ofile.is_open()){
        return false;
    }
    //write header info to file
    ofile << "P5" << std::endl;
    ofile << width << " " << height << std::endl;
    ofile << "255" << std::endl;

    //make entire image in memory black
    for(size_t i=0; i<height; ++i){
        for(size_t j=0; j<width; ++j){
            image[i][j] = '\0';
        }
    }
    //loop over all components
    for(ConnectedComponent c:components){
        //overwrite image unique vector for this array

        //loop over vector of included components in c
        for(std::pair<int,int> p :c.getPixels()){
            //turn all pixels in p into 255
            image[p.first][p.second] = 255;
        }
    }
    
    //then write contents of unique pointer to outfile
    for(size_t i=0; i<height; ++i){
        for(size_t j=0; j<width; ++j){
            ofile.write(&image[i][j],1);
        }
    }
    //close file
    ofile.close();
    return true;

}
// return number of components
int PKNNIV001::PGMimageProcessor::getComponentCount(void) const{
    return int{components.size()};
}

// return number of pixels in largest component
int PKNNIV001::PGMimageProcessor::getLargestSize(void) const{
    int largest{0};

    for(ConnectedComponent c:components){
        if(c.getNoPixels()>largest){
            largest = c.getNoPixels();
        }
    }

    return largest;
}
// return number of pixels in smallest component
int PKNNIV001::PGMimageProcessor::getSmallestSize(void) const{
    int smallest{components[0].getNoPixels()};

    for(ConnectedComponent c: components){
        if(c.getNoPixels()<smallest){
            smallest = c.getNoPixels();
        }
    }
    return smallest;
}

/* print the data for a component to std::cout
see ConnectedComponent class;
print out to std::cout: component ID, number of pixels*/
void PKNNIV001::PGMimageProcessor::printComponentData(const PKNNIV001::ConnectedComponent & theComponent) const{
    std::cout << "Component ID: " << theComponent.getID() << "Number of pixels: " << theComponent.getNoPixels() << std::endl;
}