#include <iostream>
#include <string>
#include <vector>
#include <fstream>


static uint32_t totalAllocatedMemory;

void* operator new(size_t size) {
    totalAllocatedMemory += size;
    return malloc(size);
}

static void PrintMemoryUsage() {
    std::cout << "Memory Usage: " << totalAllocatedMemory << " bytes\n";
}

class Tree {
private:
    std::string name;
    std::string barkColor;
    std::string leafColor;
    int height;
    int x;
    int y;

public:
    Tree(const std::string& name,
         const std::string& barkColor,
         const std::string& leafColor,
         int height,
         int x,
         int y)
        : name(name),
          barkColor(barkColor),
          leafColor(leafColor),
          height(height),
          x(x),
          y(y) {}

    void draw() const {
        std::cout << "Drawing a " << name << " tree with " << barkColor << " bark, "
                  << leafColor << " leaves, and a height of " << height
                  << " meters at position (" << x << ", " << y << ")" << std::endl;
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

class ForestManager {
private:
    std::vector<Tree> trees;

public:
    void plantTree(int x, int y, const std::string& name, const std::string& barkColor,
                   const std::string& leafColor, int height) {
        std::cout << std::endl
                  << "ForestManager : Trying to plant a " << name << " tree at position (" << x << ", " << y << ")"
                  << std::endl;
        Tree* tree = new Tree(name, barkColor, leafColor, height, x, y);
        trees.push_back(*tree);
        std::cout << "ForestManager : Tree of type " << name << " planted." << std::endl;
    }

    void drawForest() const {
        std::cout << std::endl
                  << "ForestManager : Drawing the forest"
                  << std::endl;
        for (const auto& tree : trees) {
            tree.draw();
        }
    }

    void deleteTree(int x, int y)
    {
        std::cout << std::endl
                  << "ForestManager : Trying to delete a tree at position (" << x << ", " << y << ")" << std::endl;
        for (auto it = trees.begin(); it != trees.end(); ++it)
        {
            if(it->getX() == x && it->getY() == y)
            {
                trees.erase(it);
                std::cout << "ForestManager : Tree at position (" << x << ", "
                          << y << ") deleted." << std::endl;
                break;
            }
        }
    }

    auto getTreeCount() const { return trees.size(); }
};

int main() {

    ForestManager forest;
    std::vector<int> memory_y;
    std::vector<int> x_axis;

    for (int i = 1; i <= 1000; i++) {
        forest.plantTree(i, 1, "Oak", "Grey", "Green", 30);
        forest.plantTree(i, 2, "Pine", "Red-Brown", "Dark Green", 20);
        forest.plantTree(i, 3, "Oak", "Grey", "Green", 30);
        memory_y.push_back(totalAllocatedMemory);
        x_axis.push_back(3 * i);
    }

    //temporary code just for the graphs for the presentation
    std::ofstream outFile("main_2.txt");
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
