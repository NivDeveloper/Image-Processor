#include "ConnectedComponent.h"
#include <string>
#ifndef _PGMIMAGEPROCESSOR_H_
#define _PGMIMAGEPROCESSOR_H_

namespace PKNNIV001{

    class PGMimageProcessor{

        private:

        public:
            //BIG 6----------------
            //Default constructor
            PGMimageProcessor();
            //copy constructor
            PGMimageProcessor(const PGMimageProcessor &rhs);
            //move constructor
            PGMimageProcessor(PGMimageProcessor &&rhs);
            //copy assignment
            PGMimageProcessor operator=(const PGMimageProcessor &rhs);
            //move assignment
            PGMimageProcessor operator=(PGMimageProcessor &&rhs);
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