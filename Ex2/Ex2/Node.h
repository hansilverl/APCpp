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
	bool getName(std::string& output);
	void print();
};
