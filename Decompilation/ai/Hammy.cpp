#include <cstdint>

namespace EORAI {
    uint32_t GetHammyState(void* characterInstance) {
        if (characterInstance == nullptr) return 0;
        
        
        if (EngineQueryFlag(characterInstance, 0x4292f8) != 0) return 0;
        if (EngineQueryFlag(characterInstance, 0x429300) != 0) return 1;
        if (EngineQueryFlag(characterInstance, 0x429308) != 0) return 2;
        if (EngineQueryFlag(characterInstance, 0x429310) != 0) return 0;
        
        return 3;
    }
}