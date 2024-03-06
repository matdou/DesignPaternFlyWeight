#ifndef TREEFACTORY_H
#define TREEFACTORY_H

#include <map>

#include "Tree.h"

class TreeFactory {
   private:
    std::map<std::string, Tree*> trees;

   public:
    ~TreeFactory();
    Tree* getTree(const std::string& name);
};

#endif  // TREEFACTORY_H
