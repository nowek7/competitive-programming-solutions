#include <string>

#include <iostream>

int strStr(std::string haystack, std::string needle)
{
    if (needle.length() > haystack.length()) {
        return -1;
    }

    for (int i = 0, j = i + needle.length(); j < haystack.length(); ++i, ++j) {
        if (haystack.substr(i, j) == needle) {
            return i;
        }
    }

    return -1;
}

int strStr_2(std::string haystack, std::string needle)
{
    return haystack.find(needle);
}

int strStr_3(std::string haystack, std::string needle)
{
    if (needle.length() > haystack.length()) {
        return -1;
    }

    if (needle.empty()) {
        return -1;
    }

    for (int i = 0, j = 0; i < haystack.length(); ++i) {
        if (haystack[i] == needle[j]) {
            ++j;
        } else {
            std::cout << i << " " << j << '\n';
            i = i - j;
            j = 0;
        }

        if (j == needle.length()) {
            return i - j + 1;
        }
    }

    return -1;
}

int main()
{
    // 28. Find the Index of the First Occurrence in a String
    {
        std::string haystack = "sadbutsad";
        std::string needle = "sad";
        std::cout << strStr(haystack, needle) << '\n';
    }

    {
        std::string haystack = "leetcode";
        std::string needle = "leeto";
        std::cout << strStr(haystack, needle) << '\n';
    }

    {
        std::string haystack = "hello";
        std::string needle = "ll";
        std::cout << strStr_3(haystack, needle) << '\n';
    }

    {
        std::string haystack = "a";
        std::string needle = "a";
        std::cout << strStr(haystack, needle) << '\n';
    }

    {
        std::string haystack = "ala";
        std::string needle = "al";
        std::cout << strStr(haystack, needle) << '\n';
    }

    return 0;
}