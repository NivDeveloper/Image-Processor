#include <vector>
#ifndef _CONNECTEDCOMPONENT_H_
#define _CONNECTEDCOMPONENT_H_


 namespace PKNNIV001{

    class ConnectedComponent{

        private:
            int nopix;      //total no. of pixels
            int id;         //unique identifier 0...
            std::vector<std::pair<int,int>> pixels; 
        public:
            //BIG 6----------------
            ConnectedComponent(int no, int ID, std::vector<std::pair<int,int>> pix);
            //constructor with just ID
            ConnectedComponent(int ID);
            //copy constructor
            ConnectedComponent(const ConnectedComponent &rhs);
            //move constructor
            ConnectedComponent(ConnectedComponent &&rhs);
            //copy assignment
            ConnectedComponent &operator=(const ConnectedComponent &rhs);
            //move assignment
            ConnectedComponent &operator=(ConnectedComponent &&rhs);
            //destructor
            ~ConnectedComponent();
            //---------------------

            //methods to expose data to other classes
            //increment no.pixels
            void incPixels(){nopix++;}
            
            //add pixel
            void addPixel(int y, int x){pixels.push_back(std::make_pair(y,x));}

            //get nopix
            int getNoPixels(void) const {return int{nopix};}

            //getID
            int getID(void) const { return int{id};}

            //get pixels - returns vector of all the points in a component
            std::vector<std::pair<int,int>> getPixels(void){return pixels;}



    };
 }

#endif