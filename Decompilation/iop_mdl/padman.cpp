#include <iostream>

namespace PadMan {
    void InitializePadManager(int highPriority, int lowPriority) {
        if (highPriority <= lowPriority) {
            std::cerr << "PADMAN : high prio thread must be higher than low prio thread\n";
            return;
        }
        std::cout << "padman: thread priority: high=" << highPriority << ", low=" << lowPriority << "\n";
    }

    void HandleError(int code) {
        if (code == -1) {
            std::cerr << "padman: RegisterLibraryEntries Faild\n";
        } else if (code == -2) {
            std::cerr << "padman: sif_init Faild\n";
        } else {
            std::fprintf(stderr, "invalid function code (%03x)\n", code);
        }
    }
}