#include "ConcreteTrees.h"

// The Oak class represents a concrete Flyweight. It inherits from the Tree class,
// which acts as the Flyweight interface. By extending the Tree class, Oak specifies
// its unique intrinsic state (name, barkColor, leafColor, height) shared across instances.
Oak::Oak() : Tree("Oak", "Grey", "Green", 30) {}

// The same principle applies to the rest of the tree classes.
Pine::Pine() : Tree("Pine", "Red-Brown", "Dark Green", 20) {}

Maple::Maple() : Tree("Maple", "Brown", "Red", 25) {}

Birch::Birch() : Tree("Birch", "White", "Green", 20) {}

Willow::Willow() : Tree("Willow", "Grey", "Green", 15) {}

// These constructors showcase how different tree types share the same structure (intrinsic state).
