#ifndef CONCRETETREES_H
#define CONCRETETREES_H

#include "Tree.h"

class Oak : public Tree {
public:
    Oak();
};

class Pine : public Tree {
public:
    Pine();
};

class Maple : public Tree {
public:
    Maple();
};

class Birch : public Tree {
public:
    Birch();
};

class Willow : public Tree {
public:
    Willow();
};

class UnsharedTree : public Tree {
public:
    using Tree::Tree;
};

#endif // CONCRETETREES_H
