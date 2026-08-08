#include "memorycard.h"
#include <fstream>
#include <cstring>

uint32_t MemoryCardManager::ComputeCRC32(const uint8_t* data, size_t size) {
    uint32_t crc = 0xFFFFFFFF;
    for (size_t i = 0; i < size; ++i) {
        crc ^= data[i];
        for (int j = 0; j < 8; ++j) {
            crc = (crc >> 1) ^ (-(int)(crc & 1) & 0xEDB88320);
        }
    }
    return ~crc;
}

bool MemoryCardManager::ReadSaveHeader(const std::string& filePath, SaveHeader& outHeader) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) return false;
    
    file.read(reinterpret_cast<char*>(&outHeader), sizeof(SaveHeader));
    return file.good();
}

bool MemoryCardManager::WriteSaveFile(const std::string& filePath, const std::string& levelName, const std::vector<uint8_t>& bodyData) {
    std::ofstream file(filePath, std::ios::binary);
    if (!file.is_open()) return false;

    SaveHeader header = {};
    std::memcpy(header.magic, "OTHSAVE", 8);
    std::strncpy(header.levelName, levelName.c_str(), sizeof(header.levelName) - 1);
    header.bodyChecksum = ComputeCRC32(bodyData.data(), bodyData.size());

    // Write header, body, and footer (1:1 copy of header)
    file.write(reinterpret_cast<const char*>(&header), sizeof(SaveHeader));
    file.write(reinterpret_cast<const char*>(bodyData.data()), bodyData.size());
    file.write(reinterpret_cast<const char*>(&header), sizeof(SaveHeader));

    return true;
}