#include "node.h"
#include "graph.h"
#include <iostream>
#include <string>

int main() {
    Graph socialNetwork;

    // Adding users
    socialNetwork.addNode("Alice");
    socialNetwork.addNode("Bob");
    socialNetwork.addNode("Hannah");
    socialNetwork.addNode("Evyatar");
    socialNetwork.addNode("Shlomi");
    socialNetwork.addNode("Jack");

	socialNetwork.addNode("Bob");  // should print "already exists"

    // Adding friendships
    socialNetwork.addEdge("Alice", "Bob");
    socialNetwork.addEdge("Bob", "Hannah");
    socialNetwork.addEdge("Hannah", "Evyatar");
    socialNetwork.addEdge("Alice", "Shlomi");
    socialNetwork.addEdge("Shlomi", "Jack");

	socialNetwork.addEdge("Bob", "Alice");  // should print "already friends"

    // Checking and printing the paths
	std::cout << "Path from Bob to Evyatar: ";  // Should print Bob -> Hannah -> Evyatar
    socialNetwork.printPath("Bob", "Evyatar");

    std::cout << "Path from Alice to Jack: ";
	socialNetwork.printPath("Alice", "Jack");   // Should print Alice -> Shlomi -> Jack

    std::cout << "Path from Alice to Alice: ";
	socialNetwork.printPath("Alice", "Alice");  // Should print "Adam karov etzel atzmo."

    std::cout << "Path from Bob to Charlie: "; // Should print not found
    socialNetwork.printPath("Bob", "Jeff");


    return 0;
}