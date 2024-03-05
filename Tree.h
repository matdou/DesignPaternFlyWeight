#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>

/// The 'Flyweight' abstract class
class Tree {
protected:
    std::string name;
    std::string barkColor;
    std::string leafColor;
    int height;

public:
    Tree(const std::string &name, const std::string &barkColor, const std::string &leafColor, int height);
    virtual ~Tree() = default;
    virtual void draw(int x, int y) const;
};

#endif // TREE_H
