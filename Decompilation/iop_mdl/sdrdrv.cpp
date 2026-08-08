#include <iostream>

namespace SDRDrv {
    void InitializeDriver(int mainPriority, int callbackPriority) {
        if (callbackPriority > mainPriority) {
            std::cerr << "SDR driver ERROR: callback th. priority is higher than main th. priority.\n";
            return;
        }
        std::cout << "SDR driver: thread priority: main=" << mainPriority << ", callback=" << callbackPriority << "\n";
        std::cout << "SDR callback thread created\n";
    }

    void ShutdownDriver() {
        std::cout << "SDR callback thread deleted\n";
        std::cout << "sdrdrv: unloaded!\n";
        std::cout << "Exit rsd_main\n";
    }
}