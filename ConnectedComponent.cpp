#include "ConnectedComponent.h"
#include <iostream>


//default constructor
PKNNIV001::ConnectedComponent::ConnectedComponent(int no, int ID, std::vector<std::pair<int,int>> pix):
    nopix{no}, id{ID}, pixels{pix}{}

PKNNIV001::ConnectedComponent::ConnectedComponent(int ID):
    nopix{0}, id{ID}{}

//copy constructor
PKNNIV001::ConnectedComponent::ConnectedComponent(const ConnectedComponent &rhs):
    ConnectedComponent{rhs.nopix,rhs.nopix,rhs.pixels}{}

//move constructor
PKNNIV001::ConnectedComponent::ConnectedComponent(ConnectedComponent &&rhs):
    nopix{rhs.nopix}, id{rhs.id}, pixels{rhs.pixels}{}


//copy assignment operator overloading
PKNNIV001::ConnectedComponent &PKNNIV001::ConnectedComponent::operator=(const ConnectedComponent &rhs){
    nopix = rhs.nopix;
    id = rhs.id;
    pixels = rhs.pixels;
    return *this;
}

//move assignment operator overloading
PKNNIV001::ConnectedComponent &PKNNIV001::ConnectedComponent::operator=(ConnectedComponent &&rhs){
    nopix = rhs.nopix;
    id = rhs.id;
    pixels = rhs.pixels;
    return *this;
}


//destructor
PKNNIV001::ConnectedComponent::~ConnectedComponent(){

}