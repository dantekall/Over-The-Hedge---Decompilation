#include <iostream>
#include <cstdlib>
#include <new>

namespace EORDebug {

    // Global ProDG memory tracking counters
    static size_t g_AllocatedBytes = 0;
    static size_t g_AllocationCount = 0;

    void* ProDG_Malloc(size_t size) {
        void* ptr = std::malloc(size);
        if (!ptr) {
            std::cerr << "[ProDG FATAL]: Memory allocation failed! Exception handling requires access to heap memory.\n";
            throw std::bad_alloc();
        }
        g_AllocatedBytes += size;
        g_AllocationCount++;
        return ptr;
    }

    void ProDG_Free(void* ptr, size_t sizeBytes = 0) {
        if (ptr) {
            std::free(ptr);
            if (g_AllocatedBytes >= sizeBytes) {
                g_AllocatedBytes -= sizeBytes;
            }
            if (g_AllocationCount > 0) {
                g_AllocationCount--;
            }
        }
    }

    void* ProDG_Calloc(size_t num, size_t size) {
        void* ptr = std::calloc(num, size);
        if (!ptr) {
            std::cerr << "[ProDG FATAL]: Calloc failed! Insufficient heap space.\n";
            throw std::bad_alloc();
        }
        g_AllocatedBytes += (num * size);
        g_AllocationCount++;
        return ptr;
    }

    void* ProDG_Realloc(void* ptr, size_t newSize) {
        void* newPtr = std::realloc(ptr, newSize);
        if (!newPtr && newSize > 0) {
            std::cerr << "[ProDG FATAL]: Realloc failed! Heap reallocation error.\n";
            throw std::bad_alloc();
        }
        return newPtr;
    }

    void InitializeProDGRuntime() {
        std::cout << "[ProDG RUNTIME]: Initialized memory tracking hooks and hardware diagnostic channels.\n";
        std::cout << "[ProDG RUNTIME]: Current Heap Usage -> " << g_AllocatedBytes << " bytes across " << g_AllocationCount << " allocations.\n";
    }
}