#include "TreeFactory.h"

#include <iostream>

#include "ConcreteTrees.h"

// Destructor to clean up dynamically allocated Tree objects.
// Ensures proper resource management by deleting all shared Tree instances
// when the factory is destroyed, preventing memory leaks.
TreeFactory::~TreeFactory() {
    for (const auto &[key, value] : trees) {
        delete value;  // Free memory allocated for Tree objects.
    }
}

// Retrieves a tree of the specified type. If the tree doesn't exist,
// it is created and added to the pool of flyweight objects.
// This method demonstrates the essence of the Flyweight pattern:
// reusing shared instances to minimize memory usage.
Tree *TreeFactory::getTree(const std::string &name) {
    // Check if a tree of the requested type already exists in the pool.
    if (trees.find(name) == trees.end()) {
        // If the tree does not exist, create a new instance based on the name.
        // This conditional creation ensures that only needed types of trees are
        // stored.
        if (name == "Oak") {
            trees[name] = new Oak();
        } else if (name == "Pine") {
            trees[name] = new Pine();
        } else if (name == "Maple") {
            trees[name] = new Maple();
        } else if (name == "Birch") {
            trees[name] = new Birch();
        } else if (name == "Willow") {
            trees[name] = new Willow();
        } else {
            // If the requested tree type is not supported, inform the user and
            // return nullptr.
            std::cout << "No tree of type " << name
                      << " found. Returning a null pointer." << std::endl;
            return nullptr;
        }
    }
    // Return the existing or newly created tree from the pool.
    return trees[name];
}
