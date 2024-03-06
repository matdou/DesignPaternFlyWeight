#include "MemoryTracker.h"

uint32_t totalAllocatedMemory = 0;

// Overload the global new operator to track memory allocation.
// This is an example of custom memory management in C++.
void* operator new(size_t size) {
    totalAllocatedMemory += size;
    return malloc(size);
}

// Print the current memory usage, illustrating the effectiveness of the
// Flyweight pattern.
void PrintMemoryUsage() {
    std::cout << "Memory Usage: " << totalAllocatedMemory << " bytes\n";
}

// Reset the memory usage counter, useful for comparative memory usage analysis.
void ResetMemoryUsage() { totalAllocatedMemory = 0; }
