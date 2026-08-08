#include <string>
#include <vector>
#include <iostream>

namespace EORDebug {
    struct DebugMenuItem {
        std::string label;
        bool isHighlighted;
        int currentValue;
    };

    class DebugMenuSystem {
    private:
        std::vector<DebugMenuItem> items;
        bool isVisible;

    public:
        DebugMenuSystem() : isVisible(false) {}

        void ToggleMenu() { 
            isVisible = !isVisible; 
        }
        
        void AddItem(const std::string& label, int initialVal = 0) {
            items.push_back({label, false, initialVal});
        }

        void RenderOverlay() {
            if (!isVisible) return;
            
            std::cout << "--- EOR ENGINE DEBUG OVERLAY ---" << std::endl;
            for (size_t i = 0; i < items.size(); ++i) {
                std::cout << (items[i].isHighlighted ? "[HIGHLIGHTED] > " : "              ") 
                          << items[i].label << " : " << items[i].currentValue << std::endl;
            }
            std::cout << "--------------------------------" << std::endl;
        }
    } debugMenu;
}