#include "MemoryTracker.h"

uint32_t totalAllocatedMemory = 0;

void* operator new(size_t size) {
    totalAllocatedMemory += size;
    return malloc(size);
}

void PrintMemoryUsage() {
    std::cout << "Memory Usage: " << totalAllocatedMemory << " bytes\n";
}
