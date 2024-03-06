#include "TreeFactory.h"
#include "ConcreteTrees.h"
#include <iostream>

TreeFactory::~TreeFactory() {
    for (const auto &[key, value] : trees) {
        delete value;
    }
}

Tree* TreeFactory::getTree(const std::string &name) {
    if (trees.find(name) == trees.end()) {
        if (name == "Oak") {
            trees[name] = new Oak();
        } else if (name == "Pine") {
            trees[name] = new Pine();
        } else if (name == "Maple") {
            trees[name] = new Maple();
        } else if (name == "Birch") {
            trees[name] = new Birch();
        } else if (name == "Willow") {
            trees[name] = new Willow();
        } else {
            std::cout << "No tree of type " << name << " found. Returning a null pointer." << std::endl;
            return nullptr;
        }
    }
    return trees[name];
}
