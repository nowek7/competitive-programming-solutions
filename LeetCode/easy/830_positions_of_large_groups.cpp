#include <vector>
#include <string>
#include <iostream>

std::vector<std::vector<int>> largeGroupPositions(std::string s)
{
    std::vector<std::vector<int>> result;
    int start = 0;
    int end = 1;
    while (end < s.size()) {
        if (s.at(start) != s.at(end)) {
            if (end - start >= 3) {
                result.push_back({start, end - 1});
            }
            start = end;
        }
        ++end;
    }

    if (end - start >= 3) {
        result.push_back({start, end - 1});
    }

    return result;
}

int main()
{
    // 830. Positions of Large Groups
    {
        std::string s = "abbxxxxzzy";
        for (auto&& entry: largeGroupPositions(s)) {
            std::cout << "[" << entry.at(0) << ", " << entry.at(1) << "]" << '\n';
        }
    }
    std::cout << "------------" << '\n';
    {
        std::string s = "abcdddeeeeaabbbcd";
        for (auto&& entry: largeGroupPositions(s)) {
            std::cout << "[" << entry.at(0) << ", " << entry.at(1) << "]" << '\n';
        }
    }
    std::cout << "------------" << '\n';
    {
        std::string s = "abbcc";
        for (auto&& entry: largeGroupPositions(s)) {
            std::cout << "[" << entry.at(0) << ", " << entry.at(1) << "]" << '\n';
        }
    }
    std::cout << "------------" << '\n';

    return 0;
}