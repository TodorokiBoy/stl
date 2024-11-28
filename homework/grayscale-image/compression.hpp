#pragma once

#include <array>
#include <cstddef>  //for size_t
#include <cstdint>  //for uint8_t
#include <utility>  //for std::pair
#include <vector>

constexpr size_t width = 32;
constexpr size_t height = 32;

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, width>, height> bitmap);

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& bitmap);

void printMap(std::array<std::array<uint8_t, width>, height> bitmap);
