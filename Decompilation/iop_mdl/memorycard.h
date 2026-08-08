#ifndef MEMORYCARD_H
#define MEMORYCARD_H

#include <string>
#include <vector>
#include <cstdint>

struct SaveHeader {
    char magic[16];
    char levelName[32];
    uint32_t bodyChecksum;
    uint32_t reserved;
};

class MemoryCardManager {
private:
    uint32_t ComputeCRC32(const uint8_t* data, size_t size);

public:
    bool ReadSaveHeader(const std::string& filePath, SaveHeader& outHeader);
    bool WriteSaveFile(const std::string& filePath, const std::string& levelName, const std::vector<uint8_t>& bodyData);
};

#endif