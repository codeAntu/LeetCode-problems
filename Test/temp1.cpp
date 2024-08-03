#include <iostream>
#include <vector>

// Definition of the Node structure
struct Node {
    int value;
    std::vector<int> children; // Indices of children in the nodes vector
};

// Function to collect values from the subtree rooted at 'nodeIndex'
void collectSubtreeValues(int nodeIndex, const std::vector<Node>& nodes, std::vector<int>& collectedValues) {
    // Add the current node's value to the collected values
    collectedValues.push_back(nodes[nodeIndex].value);

    // Recursively collect values from the children
    for (int childIndex : nodes[nodeIndex].children) {
        collectSubtreeValues(childIndex, nodes, collectedValues);
    }
}

// Example usage
int main() {
    // Example tree:
    //       1
    //      / \
    //     2   3
    //    /   / \
    //   4   5   6
    std::vector<Node> nodes = {
        {1, {1, 2}}, // Node 0 has children 1 and 2
        {2, {3}},    // Node 1 has child 3
        {3, {4, 5}}, // Node 2 has children 4 and 5
        {4, {}},     // Node 3 has no children
        {5, {}},     // Node 4 has no children
        {6, {}}      // Node 5 has no children
    };

    std::vector<int> collectedValues;
    collectSubtreeValues(0, nodes, collectedValues); // Collect values starting from root node (index 0)

    // Print collected values
    std::cout << "Collected Subtree Values: ";
    for (int value : collectedValues) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}