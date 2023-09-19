#include <algorithm>
#include <string>
#include <unordered_map>
#include <iostream>

bool isAnagram(std::string str1, std::string str2)
{
    if (str1.length() != str2.length()) {
        return false;
    }

    std::unordered_map<char, int> char_frequency;
    for (char c : str1) {
        char_frequency[c]++;
    }

    for (char c : str2) {
        if (char_frequency[c] == 0) {
            return false;
        }
        char_frequency[c]--;
    }

    return true;
}

bool isAnagram_v2(std::string str1, std::string str2)
{
    if (str1.length() != str2.length()) {
        return false;
    }

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    return str1 == str2;
}

int main() {
    // 242. Valid Anagram
    std::cout << std::boolalpha;
    std::cout << isAnagram_v2("listen", "silent") << std::endl;
    std::cout << isAnagram("eleven plus two", "twelve plus one") << std::endl;
    std::cout << isAnagram_v2("hello", "world") << std::endl;

    return 0;
}
