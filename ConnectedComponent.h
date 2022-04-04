#include <vector>
#ifndef _CONNECTEDCOMPONENT_H_
#define _CONNECTEDCOMPONENT_H_

//int no of pixels
// int unique integer identifier, starting at 0
//store pixzels as std::vector<std::pair<int,int>>
//public methods to expose data to other classes
 namespace PKNNIV001{

    class ConnectedComponent{

        private:
            int nopix,id;
            std::vector<std::pair<int,int>> pixels;
        public:
            //BIG 6----------------
            ConnectedComponent();
            //copy constructor
            ConnectedComponent();
            //move constructor
            ConnectedComponent();
            //copy assignment
            ConnectedComponent operator=(const ConnectedComponent &rhs);
            //move assignment
            ConnectedComponent operator=(ConnectedComponent &&rhs);
            //destructor
            ~ConnectedComponent();
            //---------------------

            //methods to expose data to other classes



    };
 }

#endif