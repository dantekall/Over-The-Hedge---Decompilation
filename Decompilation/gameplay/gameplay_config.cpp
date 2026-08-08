#include <string>
#include <vector>

namespace GameplayConfig {
    // Character Identifiers
    const char* const CHAR_VERNE = "Verne";
    const char* const CHAR_STELLA = "Stella";
    const char* const CHAR_HAMMY = "Hammy";

    // Player Slot Identifiers
    const char* const SLOT_PLAYER_1 = "Player1Character";
    const char* const SLOT_PLAYER_2 = "Player2Character";

    // Hardware / Controller Settings (Rumble & Feedback)
    const char* const HW_PS2_DETAILS = "PS2Details";
    const char* const SETTING_SMALL_MOTOR = "SmallMotorOn";
    const char* const SETTING_LARGE_MOTOR = "LargeMotorSetting";
    const char* const SETTING_DURATION = "Duration";

    // Difficulty Options
    const char* const DIFF_NORMAL = "normal";
    const char* const DIFF_EASY = "easy";
    const char* const DIFF_HARD = "hard";

    // Configuration Manager Registry Structure
    struct GameSettingsDatabase {
        std::vector<std::string> availableCharacters = { CHAR_VERNE, CHAR_STELLA, CHAR_HAMMY };
        std::vector<std::string> difficultyTiers = { DIFF_EASY, DIFF_NORMAL, DIFF_HARD };
        
        bool enableRumble = true;
        int smallMotorIntensity = 0;
        int largeMotorIntensity = 0;
        int vibrationDurationMs = 0;
    };
}