#include <cstdlib>
#include <iostream>

namespace EORDebug {
    void* HookedMalloc(size_t size) {
        void* ptr = std::malloc(size);
        if (!ptr) {
            std::cerr << "[DEBUG ASSERT]: Memory allocation failed! Exception handling requires access to heap memory.\n";
        }
        return ptr;
    }

    void HookedFree(void* ptr) {
        if (ptr) std::free(ptr);
    }

    void InitializeDefaultMonitorFactory() {
        std::cout << "[DEBUG MONITOR]: Initializing ProDG runtime performance monitors and default telemetry factories.\n";
    }
}

int main() {
    EORDebug::InitializeDefaultMonitorFactory();
    return 0;
}
