#include "sort.hpp"
#include <algorithm>
#include <vector>

std::deque<std::string> lengthSort(std::forward_list<std::string> list) {
    std::deque<std::string> result(list.begin(), list.end());

    std::sort(result.begin(), result.end(), [](std::string a, std::string b) {
        if (a.length() != b.length())
            return a.length() < b.length();

        return a < b;
    });

    return result;
}