#include "compression.hpp"
#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> bitmap) {
    std::vector<std::pair<uint8_t, uint8_t>> result;

    uint8_t count;

    for (const auto& row : bitmap) {
        count = 1;
        for (size_t i = 1; i < row.size(); i++)
        {
            if (row[i] != row[i-1]) {
                result.emplace_back(row[i-1], count);
                count = 1;
            } else {
                count++;
            }
        }
        result.emplace_back(row.back(), count);
    }

    return result;
}


std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& bitmap) {
    std::array<std::array<uint8_t, width>, height> result;

    int i = 0;
    uint8_t remaining = bitmap[i].second;

    for (auto& row : result) {
        for (auto& element : row) {
            if (remaining == 0) {
                i++;
                remaining = bitmap[i].second;
            }

            element = bitmap[i].first;
            --remaining;
        }
    }

    return result;
}
