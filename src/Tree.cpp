#include "Tree.h"

Tree::Tree(const std::string &name, const std::string &barkColor, const std::string &leafColor, int height)
    : name(name), barkColor(barkColor), leafColor(leafColor), height(height) {}

void Tree::draw(int x, int y) const {
    std::cout << "Drawing a " << name << " tree with " << barkColor << " bark, " << leafColor << " leaves, and a height of " << height << " meters at position (" << x << ", " << y << ")" << std::endl;
}
