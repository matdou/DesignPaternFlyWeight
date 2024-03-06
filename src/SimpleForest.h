#ifndef SIMPLEFOREST_H
#define SIMPLEFOREST_H

#include "Tree.h"
#include <vector>
#include <iostream>
#include <string>

class SimpleForest {
public:
    void plantTree(const std::string& name, const std::string& barkColor, const std::string& leafColor, int height, int x, int y);
    void drawForest() const;
    void deleteTree(int x, int y);
    size_t getTreeCount() const;

private:
    std::vector<std::pair<Tree, std::pair<int, int>>> trees;
};

#endif // SIMPLEFOREST_H
