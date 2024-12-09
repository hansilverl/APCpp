#include <string>
#include <vector>

class Node {
private:
	std::string name;
	std::vector<Node*> neighbors;
public:
	Node(const std::string& input);
	void addNeighbor(Node* p_neighbor);
	const std::vector<Node*>& getNeighbors();
	bool nameIs(const std::string& input);
	const std::string& getName() const; 
	void print();
};
