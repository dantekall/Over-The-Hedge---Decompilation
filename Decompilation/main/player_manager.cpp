#include <cstdint>
#include <string>

namespace EORMain {
    struct PlayerCharacterData {
        char padding[0x6ce8];
        std::string characterName; // Resolves to s_Player1Character_00429318
    };

    inline PlayerCharacterData* GetPlayer1(void* baseRegisterA2) {
        // Resolves the hardcoded offset -0x6ce8 safely
        return reinterpret_cast<PlayerCharacterData*>(
            reinterpret_cast<uint8_t*>(baseRegisterA2) - 0x6ce8
        );
    }
}