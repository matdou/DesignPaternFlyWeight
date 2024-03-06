#include "ForestManager.h"

#include <iostream>

#include "ConcreteTrees.h"

// Plant a tree at a specified location. This method utilizes the Flyweight
// pattern by retrieving a shared instance of a tree type rather than creating a
// new instance. This significantly reduces memory usage when managing large
// numbers of trees.
void ForestManager::plantTree(int x, int y, const std::string &name) {
    // Get a shared instance of a tree from the factory based on the tree's
    // name. This demonstrates the use of encapsulation and the factory design
    // pattern in conjunction with the Flyweight pattern.
    Tree *tree = factory.getTree(name);
    if (!tree) {
        std::cout << "ForestManager: Tree of type " << name
                  << " not found. Cannot plant tree." << std::endl;
        return;
    }
    // Add the tree to the forest, showcasing the separation between the
    // intrinsic state (shared tree type, color, etc.) and the extrinsic state
    // (unique position).
    trees.push_back({tree, {x, y}});
    std::cout << "ForestManager: Tree of type " << name << " planted."
              << std::endl;
}

// Plant a tree manually at a specified location without using the Flyweight
// pattern. This is used for trees that do not fit into the Flyweight pattern
// (e.g., unique or rare trees). It demonstrates flexibility in combining
// patterned and non-patterned approaches.
void ForestManager::manualPlantTree(int x, int y, const std::string &name,
                                    const std::string &barkColor,
                                    const std::string &leafColor, int height) {
    // Directly create a new instance of a tree, bypassing the Flyweight
    // pattern. This illustrates the use of dynamic memory allocation (through
    // 'new') in C++.
    Tree *tree = new UnsharedTree(name, barkColor, leafColor, height);
    trees.push_back({tree, {x, y}});
    std::cout << "ForestManager: Tree of type " << name << " planted manually."
              << std::endl;
}

// Draw all trees in the forest. This method iterates over the collection of
// trees, calling the draw method on each one, which is an example of
// polymorphism in action. Each tree, regardless of its type, knows how to draw
// itself.
void ForestManager::drawForest() const {
    std::cout << "ForestManager: Drawing the forest" << std::endl;
    for (const auto &[tree, position] : trees) {
        tree->draw(position.first, position.second);
    }
}

// Delete a tree at a specified position. This method iterates through the
// collection of trees, removing the tree that matches the provided position,
// demonstrating the management of the extrinsic state of Flyweight objects.
void ForestManager::deleteTree(int x, int y) {
    for (auto it = trees.begin(); it != trees.end();) {
        if (it->second.first == x && it->second.second == y) {
            std::cout << "ForestManager: Tree at position (" << x << ", " << y
                      << ") deleted." << std::endl;
            it = trees.erase(it);  // Efficiently erase the tree
        } else {
            ++it;
        }
    }
}

// Return the total count of trees in the forest.
auto ForestManager::getTreeCount() const -> decltype(trees.size()) {
    return trees.size();
}
