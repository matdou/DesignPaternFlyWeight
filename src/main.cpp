#include <fstream>
#include <iostream>

#include "ForestManager.h"
#include "MemoryTracker.h"
#include "SimpleForest.h"

int main() {
    // Create an instance of ForestManager, which utilizes the Flyweight pattern
    // to manage tree objects efficiently. The Flyweight pattern is applied here
    // to minimize memory usage by sharing intrinsic states (type, color, etc.)
    // of trees across multiple locations in the forest.
    ForestManager forest;

    // These vectors track memory usage and the number of trees planted,
    // showcasing the efficiency of the Flyweight pattern.
    std::vector<int> memory_y;
    std::vector<int> x_axis;

    // Plant 1000 Oak and Pine trees using the ForestManager. The Flyweight
    // pattern allows for sharing tree data, significantly reducing memory
    // usage.
    for (int i = 1; i <= 1000; i++) {
        forest.plantTree(i, 1, "Oak");
        forest.plantTree(i, 2, "Pine");
        forest.plantTree(i, 3, "Oak");
        memory_y.push_back(totalAllocatedMemory);  // Track memory usage
        x_axis.push_back(3 * i);                   // Track number of trees
    }

    // Output the memory usage data to 'flyweight.txt' to analyze the
    // effectiveness of the Flyweight pattern in managing memory.
    std::ofstream outFile("data/flyweight.txt");
    if (outFile.is_open()) {
        for (size_t i = 0; i < memory_y.size(); ++i) {
            outFile << x_axis[i] << " " << memory_y[i] << "\n";
        }
        outFile.close();
    }

    std::cout << "----------------------------------------" << std::endl;

    // Create an instance of SimpleForest, which does not use the Flyweight
    // pattern and compares memory usage by creating a new instance of a tree
    // for every request.
    SimpleForest simpleForest;
    std::vector<int> memory_y_2;
    std::vector<int> x_axis_2;
    ResetMemoryUsage();  // Reset memory tracker for the SimpleForest comparison

    // Plant 1000 Oak and Pine trees without using the Flyweight pattern
    // to illustrate the difference in memory usage.
    for (int i = 1; i <= 1000; i++) {
        simpleForest.plantTree("Oak", "Grey", "Green", 30, i, 1);
        simpleForest.plantTree("Pine", "Red-Brown", "Dark Green", 20, i, 2);
        simpleForest.plantTree("Oak", "Grey", "Green", 30, i, 3);
        memory_y_2.push_back(totalAllocatedMemory);  // Track memory usage
        x_axis_2.push_back(3 * i);                   // Track number of trees
    }

    // Output the memory usage data for SimpleForest to 'simpleForest.txt'.
    // This data shows higher memory usage due to the lack of the Flyweight
    // pattern.
    std::ofstream outfile("data/simpleForest.txt");
    if (outfile.is_open()) {
        for (size_t i = 0; i < memory_y_2.size(); ++i) {
            outfile << x_axis[i] << " " << memory_y_2[i] << "\n";
        }
        outfile.close();
    }

    // Display the final results: the number of trees and the memory usage for
    // both implementations.
    std::cout << std::endl
              << "Number of trees in the forest : " << forest.getTreeCount()
              << std::endl;

    forest.drawForest();
    PrintMemoryUsage();
}