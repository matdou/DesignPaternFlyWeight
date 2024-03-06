#include "ForestManager.h"
#include "MemoryTracker.h"
#include <iostream>
#include <fstream>

int main()
{
    ForestManager forest;
    std::vector<int> memory_y;
    std::vector<int> x_axis;

    for (int i = 1; i <= 1000; i++) {
        forest.plantTree(i, 1, "Oak");
        forest.plantTree(i, 2, "Pine");
        forest.plantTree(i, 3, "Oak");
        memory_y.push_back(totalAllocatedMemory);
        x_axis.push_back(3 * i);
    }

    //temporary code just for the graphs for the presentation
    std::ofstream outFile("main.txt");
    if (outFile.is_open()) {
        for (size_t i = 0; i < memory_y.size(); ++i) {
            outFile << x_axis[i] << " " << memory_y[i] << "\n";
        }
        outFile.close();
    }
    //

    std::cout << std::endl
              << "Number of trees in the forest : " << forest.getTreeCount() << std::endl;

    forest.drawForest();
    PrintMemoryUsage();
}

