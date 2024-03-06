#include "ForestManager.h"
#include "ConcreteTrees.h"
#include <iostream>

void ForestManager::plantTree(int x, int y, const std::string &name) {
    Tree* tree = factory.getTree(name);
    if (!tree) {
        std::cout << "ForestManager: Tree of type " << name << " not found. Cannot plant tree." << std::endl;
        return;
    }
    trees.push_back({tree, {x, y}});
    std::cout << "ForestManager: Tree of type " << name << " planted." << std::endl;
}

void ForestManager::manualPlantTree(int x, int y, const std::string &name, const std::string &barkColor, const std::string &leafColor, int height) {
    Tree* tree = new UnsharedTree(name, barkColor, leafColor, height);
    trees.push_back({tree, {x, y}});
    std::cout << "ForestManager: Tree of type " << name << " planted manually." << std::endl;
}

void ForestManager::drawForest() const {
    std::cout << "ForestManager: Drawing the forest" << std::endl;
    for (const auto& [tree, position] : trees) {
        tree->draw(position.first, position.second);
    }
}

void ForestManager::deleteTree(int x, int y) {
    for (auto it = trees.begin(); it != trees.end(); ) {
        if (it->second.first == x && it->second.second == y) {
            std::cout << "ForestManager: Tree at position (" << x << ", " << y << ") deleted." << std::endl;
            it = trees.erase(it);
        } else {
            ++it;
        }
    }
}

auto ForestManager::getTreeCount() const -> decltype(trees.size()) {
    return trees.size();
}
