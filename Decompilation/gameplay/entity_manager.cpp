#include <cstdint>

namespace EOREngine {
    // Modernized equivalent of FUN_0013faf8
    void DispatchEntityParameters(void* param1, void* param2, int64_t param3) {
        // Parameter setup and stack array preparation
        int stackA[4] = {0};
        int stackB[4] = {0};

        if (param3 != 0) {
            // Process conditional sub-parameters
            stackB[0] = static_cast<int>(param3);
        }

        // Execute core system routing based on param3 presence
        if (param3 == 0) {
            ExecuteEngineHook(0x412979, 0x42a958, stackA[0]);
        } else {
            ExecuteEngineHook(0x412979, 0x42a950, stackA[0], stackB[0]);
        }
    }
}