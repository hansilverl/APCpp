#include "Node.h"

// The class builder copies the contents of the input parameter to the class name element. 
Node::Node(const std::string& input) : name(input) {
	this->name = input;
}

/*
The addNeighbor function adds a friend to the list of friends saved in the neighbors variable.
It does not allocates memory space to a new user on the network, but adds a pointer to a friend for whom space has already been assigned.*/


