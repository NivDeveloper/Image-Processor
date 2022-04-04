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



    };
 }

#endif