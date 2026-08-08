#include <cstdlib>
#include <iostream>
#include <new>

namespace EOROS {
    // Safe memory allocator wrapper replacing standard new/malloc hooks
    void* SafeAllocate(size_t size) {
        void* ptr = std::malloc(size);
        if (!ptr) {
            std::cerr << "[CRITICAL ERROR]: bad_alloc caught! Heap memory exhausted.\n";
            throw std::bad_alloc();
        }
        return ptr;
    }
}