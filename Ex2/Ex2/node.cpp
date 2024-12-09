#include "node.h"

// copies the contents of the input parameter to the class name element. 
Node::Node(const std::string& input) : name(input) {
	this->name = input;
}

/*
adds a friend to the list of friends saved in the neighbors variable.
It does not allocates memory space to a new user on the network,
but adds a pointer to a friend for whom space has already been assigned.*/
void Node::addNeighbor(Node* p_neighbor) {
	this->neighbors.push_back(p_neighbor);
}

// returns the friends list, i.e. returns the neighbors variable.
const std::vector<Node*>& Node::getNeighbors() {
	return this->neighbors;
}


// The namels returns true if the input parameter is the same as name, and false if not.
bool Node::nameIs(const std::string& input)
{
	return this->name == input;
}

// prints the name of the node.
void Node::print()
{
	std::cout << this->name << std::endl;
}


const std::string& Node::getName() const
{
	return this->name;
}

