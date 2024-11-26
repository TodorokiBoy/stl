#include "vowel.hpp"
#include <algorithm>
#include <array>

void removeVowels(std::vector<std::string>& vec) {
    const std::array<char, 12> vowels = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};

    for (std::string& element : vec) {
        element.erase(std::remove_if(element.begin(), element.end(),
                                     [vowels](char c) {
                                         return std::find(vowels.begin(), vowels.end(), c) != vowels.end();
                                     }),
                      element.end());
    }
}