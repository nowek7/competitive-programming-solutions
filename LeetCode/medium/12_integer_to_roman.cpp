#include <string>
#include <vector>

#include <iostream>

std::string intToRoman(int num)
{
    std::vector<std::pair<int, const char*>> romans = {
        {1000, "M"}, {900, "CM"},
        {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"},
        {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"},
        {5, "V"}, {4, "IV"},
        {1, "I"}
    };

    std::string result;
    for (auto [key, value]: romans) {
        while (key <= num) {
            result += value;
            num -= key;
        }
    }

    return result;
}

int main()
{
    // 12. Integer to Roman
    {
        int num = 3;
        std::cout << num << " -> " << intToRoman(num) << '\n';
    }

    {
        int num = 9;
        std::cout << num << " -> " << intToRoman(num) << '\n';
    }

    {
        int num = 50;
        std::cout << num << " -> " << intToRoman(num) << '\n';
    }

    {
        int num = 58;
        std::cout << num << " -> " << intToRoman(num) << '\n';
    }

    {
        int num = 1994;
        std::cout << num << " -> " << intToRoman(num) << '\n';
    }

    {
        int num = 1990;
        std::cout << num << " -> " << intToRoman(num) << '\n';
    }

    return 0;
}