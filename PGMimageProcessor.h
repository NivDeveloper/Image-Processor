#include "ConnectedComponent.h"
#include <string>
#include <vector>
#include <memory>
#ifndef _PGMIMAGEPROCESSOR_H_
#define _PGMIMAGEPROCESSOR_H_

namespace PKNNIV001{

    /*-Class that is initialized once and has array of ConnectedComponent Objects
      -Also manages and manipulates components
    */
    class PGMimageProcessor{

        private:
            std::string name;
            //pointer array holing input image in memory
            std::unique_ptr<std::unique_ptr<char []>[]> image;
            //vector to store all components
            std::vector<ConnectedComponent> components;
            int height,width; //dimensions of input image

        public:
            //BIG 6----------------
            //Default constructor
            PGMimageProcessor(std::string n);
            //copy constructor
            PGMimageProcessor(const PGMimageProcessor &rhs);
            //move constructor
            PGMimageProcessor(PGMimageProcessor &&rhs);
            //copy assignment
            PGMimageProcessor &operator=(const PGMimageProcessor &rhs);
            //move assignment
            PGMimageProcessor &operator=(PGMimageProcessor &&rhs);
            //destructor
            ~PGMimageProcessor();
            //---------------------

            int extractComponents(unsigned char threshold, int minValidSize);
            int filterComponentsBySize(int minSize, int maxSize);
            bool writeComponents(const std::string & outFileName);
            int getComponentCount(void) const;
            int getLargestSize(void) const;
            int getSmallestSize(void) const;
            void printComponentData(const ConnectedComponent & theComponent) const;

    };
}

#endif