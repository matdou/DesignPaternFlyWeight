#ifndef FORESTMANAGER_H
#define FORESTMANAGER_H

#include <vector>

#include "TreeFactory.h"

class ForestManager {
   private:
    std::vector<std::pair<Tree *, std::pair<int, int>>> trees;
    TreeFactory factory;

   public:
    void plantTree(int x, int y, const std::string &name);
    void manualPlantTree(int x, int y, const std::string &name,
                         const std::string &barkColor,
                         const std::string &leafColor, int height);
    void drawForest() const;
    void deleteTree(int x, int y);
    auto getTreeCount() const -> decltype(trees.size());
};

#endif  // FORESTMANAGER_H
