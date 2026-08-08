#include <cstdint>
#include <string>

namespace EOREngine {

    class ResourceLoader {
    private:
        uint8_t streamBufferControl[0x60];     // Offset +0x04
        const char* loaderName;                // Offset +0x18
        uint32_t isActive;                     // Offset +0x30
        uint8_t subSystemPool[0x20];           // Offset +0x50

        // External engine/kernel hooks found in binary
        static void PrerequisiteInit();
        static void InitStreamBuffer(void* controlBlock, size_t count, size_t blockSize, int flags);
        static void StartStreamer(void* controlBlock);
        static int* GetSystemVideoMode();
        static void SetAlarm(uint32_t ticks, void (*callback)(void*), void* arg);
        static void AsyncTickCallback(void* arg);

    public:
        void Initialize() {
            // 1. Run core loader prep
            PrerequisiteInit();

            // 2. Initialize internal memory tracking pool at offset +0x50
            // FUN_00316ae0(iVar3 + 0x50, 0x20, 0)
            // (Handled via internal subsystem pool setup)

            // 3. Assign subsystem identifier string
            loaderName = "Resource Loader";

            // 4. Setup primary streaming buffer (32KB block size alignment: 0x8000)
            // FUN_0030b310(iVar3 + 4, 0x60, 0x8000, 0)
            InitStreamBuffer(streamBufferControl, 0x60, 0x8000, 0);
            StartStreamer(streamBufferControl);

            // 5. Query system video configuration (PAL vs NTSC) to set alarm interval
            int* videoMode = GetSystemVideoMode();
            uint32_t alarmInterval = (*videoMode != 1) ? 0x78 : 0x80;

            // 6. Register background periodic alarm for asynchronous streaming
            SetAlarm(alarmInterval, reinterpret_cast<void(*)(void*)>(&AsyncTickCallback), this);

            // 7. Mark loader as active
            isActive = 1;
        }
    };
}