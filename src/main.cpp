#include "ForestManager.h"
#include "MemoryTracker.h"
#include "SimpleForest.h"
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
    std::ofstream outFile("data/flyweight.txt");
    if (outFile.is_open()) {
        for (size_t i = 0; i < memory_y.size(); ++i) {
            outFile << x_axis[i] << " " << memory_y[i] << "\n";
        }
        outFile.close();
    }

    
    SimpleForest simpleForest;
    memory_y.clear();
    x_axis.clear();

    for(int i = 1; i <= 1000; i++)
    {
        simpleForest.plantTree("Oak", "Grey", "Green", 30, i, 1);
        simpleForest.plantTree("Pine", "Red-Brown", "Dark Green", 20, i, 2);
        simpleForest.plantTree("Oak", "Grey", "Green", 30, i, 3);
        memory_y.push_back(totalAllocatedMemory);
        x_axis.push_back(3 * i);
    }

   

    std::ofstream outfile("data/simpleForest.txt");
    if (outfile.is_open()) {
        for (size_t i = 0; i < memory_y.size(); ++i) {
            outfile << x_axis[i] << " " << memory_y[i] << "\n";
        }
        outfile.close();
    }

    std::cout << std::endl
              << "Number of trees in the forest : " << forest.getTreeCount() << std::endl;

    forest.drawForest();
    PrintMemoryUsage();
}

