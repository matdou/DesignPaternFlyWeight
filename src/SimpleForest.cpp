#include "SimpleForest.h"

void SimpleForest::plantTree(const std::string& name, const std::string& barkColor, const std::string& leafColor, int height, int x, int y) {
    Tree tree(name, barkColor, leafColor, height);
    trees.push_back(std::make_pair(&tree, std::make_pair(x, y)));
    std::cout << "SimpleForest: Tree of type " << name << " planted at position (" << x << ", " << y << ")." << std::endl;
}

void SimpleForest::drawForest() const {
    std::cout << "SimpleForest: Drawing the forest" << std::endl;
    for (const auto& [tree, position] : trees) {
        tree->draw(position.first, position.second);
    }
}

void SimpleForest::deleteTree(int x, int y) {
    for (auto it = trees.begin(); it != trees.end(); ) {
        if (it->second.first == x && it->second.second == y) {
            std::cout << "SimpleForest: Tree at position (" << x << ", " << y << ") deleted." << std::endl;
            it = trees.erase(it);
        } else {
            ++it;
        }
    }
}

size_t SimpleForest::getTreeCount() const {
    return trees.size();
}
