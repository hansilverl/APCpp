#include "graph.h"
#include "node.h"
#include <iostream>

void Graph::addNode(const std::string& name) {
	if (findNode(name)==nullptr)
	{
		nodes.push_back(new Node(name));
	}
	std::cout << "Name already exists." << std::endl;
	return;
}

Node* Graph::findNode(const std::string& name) {
	for (size_t i = 0; i < nodes.size(); i++)
	{
		if (nodes[i]->nameIs(name)) {
			return nodes[i];
		}
	}
	return nullptr;
}

Graph::~Graph() {
	for (Node* node:nodes)
	{
		delete node;
	}
}

void Graph::addEdge(const std::string& first, const std::string& second)
{
	if (first == second)
	{
		std::cout << "Adam karov etzel atzmo." << std::endl;
		return;
	}

	Node* firstNode = findNode(first);
	Node* secondNode = findNode(second);

	if (!firstNode||!secondNode)
	{
		std::cout << "User/s not found." << std::endl;
		return;
	}

	
	for (Node* neighbor : firstNode->getNeighbors())
	{
		if (neighbor == secondNode) {
			std::cout << "Already friends." << std::endl;
			return;
		}
	}

	firstNode->addNeighbor(secondNode);
	secondNode->addNeighbor(firstNode);
}

bool Graph::areConnected(Node* p_src, Node* p_dest,
	std::vector<Node*>& current_path,
	std::vector<Node*>& min_path)
{
	if (p_src == p_dest)
	{
		if (min_path.empty() || current_path.size() < min_path.size()) {
			min_path = current_path;
		}
		current_path.pop_back();
		return true;
	}
	
	bool flag = false;

	for (Node* neighbor : p_src->getNeighbors()) {
		if (std::find(current_path.begin(), current_path.end(), neighbor) == current_path.end()) {
			if (areConnected(neighbor,p_dest,current_path,min_path))
			{
				flag = true;
			}
		}
	}

	current_path.pop_back();
	return flag;
}

void Graph::printPath(const std::string& src, const std::string& dest) {
	if(src==dest){
		std::cout << "Adam karov etzel atzmo." << std::endl;
		return;
	}

	Node* source = findNode(src);
	Node* destintion = findNode(dest);

	if (!source||!destintion)
	{
		std::cout << "User/s not found." << std::endl;
		return;
	}
		
	std::vector<Node*> current_path;
	std::vector<Node*> min_path;

	if (!areConnected(source, destintion, current_path, min_path)) {
		std::cout << "No path." << std::endl;
		return;
	}

	for (Node* node : min_path) {
		std::cout << node->getName() << " ";
	}
	std::cout << std::endl;
}


