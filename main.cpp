#include "ForestManager.h"
#include <iostream>

int main() {
    ForestManager forest;

    forest.plantTree(1, 1, "Oak");
    forest.plantTree(2, 3, "Pine");
    forest.plantTree(3, 5, "Maple");
    forest.plantTree(4, 7, "Maple");
    forest.plantTree(5, 9, "Pine");

    // Demonstrate manual planting for a tree not part of the flyweight
    forest.manualPlantTree(7, 13, "Bonzai", "Green", "Green", 1);

    std::cout << "\nNumber of trees in the forest: " << forest.getTreeCount() << std::endl;

    forest.drawForest();

    std::cout << "Press Enter to continue and delete some trees..." << std::endl;
    std::cin.get();

    forest.deleteTree(1, 1);
    forest.deleteTree(2, 3);

    std::cout << "Number of trees in the forest after deletion: " << forest.getTreeCount() << std::endl;

    return 0;
}
