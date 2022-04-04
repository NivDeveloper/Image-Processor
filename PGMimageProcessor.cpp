#include "PGMimageProcessor.h"

//contain public functions necessary to build/manipulate/ output functions
//contains private member: container of connectedComponent objects
//function to iterate over components and produce PGM image
//std::list or std::vector to store component images

//default constructor
PKNNIV001::PGMimageProcessor::PGMimageProcessor(std::vector<ConnectedComponent> comp):
    components{comp}{}

//copy constructor
PKNNIV001::PGMimageProcessor::PGMimageProcessor(const PGMimageProcessor &rhs):
    PGMimageProcessor{rhs.components}{}

//move constructor
PKNNIV001::PGMimageProcessor::PGMimageProcessor(PGMimageProcessor &&rhs):
    components{rhs.components}{}

//copy assignment
PKNNIV001::PGMimageProcessor &PKNNIV001::PGMimageProcessor::operator=(const PGMimageProcessor &rhs){
    components = rhs.components;
    return *this;
}

//move assignment
PKNNIV001::PGMimageProcessor &PKNNIV001::PGMimageProcessor::operator=(PGMimageProcessor &&rhs){
    components = rhs.components;
    return *this;
}

//destructor
PKNNIV001::PGMimageProcessor::~PGMimageProcessor(){}





/* process the input image to extract all the connected components,
based on the supplied threshold (0...255) and excluding any components
of less than the minValidSize. The final number of components that
you store in your container (after discarding undersized one)
must be returned.
*/
int PKNNIV001::PGMimageProcessor::extractComponents(unsigned char threshold, int minValidSize){}
/* iterate - with an iterator - though your container of connected
components and filter out (remove) all the components which do not
obey the size criteria pass as arguments. The number remaining
after this operation should be returned.
*/
int PKNNIV001::PGMimageProcessor::filterComponentsBySize(int minSize, int maxSize){}
/* create a new PGM file which contains all current components
(255=component pixel, 0 otherwise) and write this to outFileName as a
valid PGM. the return value indicates success of operation
*/
bool PKNNIV001::PGMimageProcessor::writeComponents(const std::string & outFileName){}
// return number of components
int PKNNIV001::PGMimageProcessor::getComponentCount(void) const{}

// return number of pixels in largest component
int PKNNIV001::PGMimageProcessor::getLargestSize(void) const{}
// return number of pixels in smallest component
int PKNNIV001::PGMimageProcessor::getSmallestSize(void) const{}
/* print the data for a component to std::cout
see ConnectedComponent class;
print out to std::cout: component ID, number of pixels
*/
void PKNNIV001::PGMimageProcessor::printComponentData(const PKNNIV001::ConnectedComponent & theComponent) const{}