#include "Tree.h"

#include <iostream>

// Constructor initializes a Tree object with its intrinsic properties:
// name, bark color, leaf color, and height. These properties are shared
// among trees of the same type, exemplifying the Flyweight pattern's
// approach to minimizing memory usage by sharing common state.
Tree::Tree(const std::string &name, const std::string &barkColor,
           const std::string &leafColor, int height)
    : name(name), barkColor(barkColor), leafColor(leafColor), height(height) {}

// The draw method displays the tree's appearance at a specific location (x, y).
// This function illustrates how the Flyweight pattern separates the intrinsic
// state (name, colors, height) shared by all instances of a tree type, from the
// extrinsic state (position) that's unique to each tree instance. The draw
// method thus takes the extrinsic state as arguments to complete its operation.
void Tree::draw(int x, int y) const {
    std::cout << "Drawing a " << name << " tree with " << barkColor << " bark, "
              << leafColor << " leaves, and a height of " << height
              << " meters at position (" << x << ", " << y << ")" << std::endl;
}

// Getter method for the tree's name. This supports the Flyweight pattern
// by allowing the identification of tree instances based on their intrinsic
// state, facilitating the sharing and management of these instances within a
// Flyweight factory.
const std::string &Tree::getName() const { return name; }
