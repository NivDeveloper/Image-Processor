#include "ConnectedComponent.h"
#include <string>
#include <vector>
#ifndef _PGMIMAGEPROCESSOR_H_
#define _PGMIMAGEPROCESSOR_H_

namespace PKNNIV001{

    class PGMimageProcessor{

        private:
            std::vector<ConnectedComponent> components;

        public:
            //BIG 6----------------
            //Default constructor
            PGMimageProcessor(std::vector<ConnectedComponent> comp);
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