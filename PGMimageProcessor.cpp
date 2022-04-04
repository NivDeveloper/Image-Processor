//contain public functions necessary to build/manipulate/ output functions
//contains private member: container of connectedComponent objects
//function to iterate over components and produce PGM image
//std::list or std::vector to store component images

/* process the input image to extract all the connected components,
based on the supplied threshold (0...255) and excluding any components
of less than the minValidSize. The final number of components that
you store in your container (after discarding undersized one)
must be returned.
*/
int extractComponents(unsigned char threshold, int minValidSize);
/* iterate - with an iterator - though your container of connected
components and filter out (remove) all the components which do not
obey the size criteria pass as arguments. The number remaining
after this operation should be returned.
*/
int filterComponentsBySize(int minSize, int maxSize);
/* create a new PGM file which contains all current components
(255=component pixel, 0 otherwise) and write this to outFileName as a
valid PGM. the return value indicates success of operation
*/
bool writeComponents(const std::string & outFileName);
// return number of components
int getComponentCount(void) const;

// return number of pixels in largest component
int getLargestSize(void) const;
// return number of pixels in smallest component
int getSmallestSize(void) const;
/* print the data for a component to std::cout
see ConnectedComponent class;
print out to std::cout: component ID, number of pixels
*/
void printComponentData(const ConnectedComponent & theComponent) const;