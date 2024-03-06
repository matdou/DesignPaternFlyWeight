#include "SimpleForest.h"

// Plant a new tree in the forest. Unlike the Flyweight pattern where instances
// are shared, this method creates a new Tree object for every call, leading to
// higher memory usage.
void SimpleForest::plantTree(const std::string &name,
                             const std::string &barkColor,
                             const std::string &leafColor, int height, int x,
                             int y) {
    Tree tree(name, barkColor, leafColor,
              height);  // Instantiating a new Tree object.
    trees.push_back(std::make_pair(
        tree, std::make_pair(
                  x, y)));  // Each tree is uniquely stored with its position.
    std::cout << "SimpleForest: Tree of type " << name
              << " planted at position (" << x << ", " << y << ")."
              << std::endl;
}

// Draws the entire forest, iterating over the collection of trees and printing
// their details. This method emphasizes individual tree objects, which, unlike
// the Flyweight pattern, are not shared.
void SimpleForest::drawForest() const {
    std::cout << "SimpleForest: Drawing the forest" << std::endl;
    for (const auto &tree : trees) {
        // Output each tree's details, including its position.
        std::cout << "SimpleForest: Tree of type " << tree.first.getName()
                  << " at position (" << tree.second.first << ", "
                  << tree.second.second << ")." << std::endl;
    }
}

// Deletes a tree at the specified position
void SimpleForest::deleteTree(int x, int y) {
    for (auto it = trees.begin(); it != trees.end();) {
        if (it->second.first == x && it->second.second == y) {
            std::cout << "SimpleForest: Tree at position (" << x << ", " << y
                      << ") deleted." << std::endl;
            it = trees.erase(it);  // Removes the tree from the collection.
        } else {
            ++it;  // Continue searching if the current tree does not match the
                   // specified position.
        }
    }
}

// Returns the total number of trees currently planted in the forest.
size_t SimpleForest::getTreeCount() const { return trees.size(); }
