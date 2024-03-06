#ifndef MEMORY_TRACKER_H
#define MEMORY_TRACKER_H

#include <cstdlib>
#include <iostream>

extern uint32_t totalAllocatedMemory;

void* operator new(size_t size);

void PrintMemoryUsage();
void ResetMemoryUsage();

#endif // MEMORY_TRACKER_H
