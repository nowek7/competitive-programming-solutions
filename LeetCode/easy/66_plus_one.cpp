#include <vector>

#include <iostream>

std::vector<int> plusOne(std::vector<int>& digits)
{
    bool isOver = false;
    for (int i = digits.size() - 1; !isOver && i >= 0; --i) {
        if (digits.at(i) + 1 > 9) {
            digits[i] = 0;
        } else {
            digits[i] += 1;
            isOver = true;
        }
    }

    if (!isOver) {
        digits.insert(digits.begin(), 1);
    }

    return digits;
}

void printDigits(const std::vector<int>& digits)
{
    std::cout << "Size -> " << digits.size() << '\n';
    for (int i = 0; i < digits.size() - 1; ++i) {
        std::cout << digits.at(i) << ", ";
    }
    std::cout << *digits.rbegin() << '\n';
}

int main()
{
    // 66. Plus One
    {
        std::vector<int> digits = {1, 2, 3};
        printDigits(plusOne(digits));
    }

    {
        std::vector<int> digits = {1};
        printDigits(plusOne(digits));
    }

    {
        std::vector<int> digits = {9};
        printDigits(plusOne(digits));
    }

    {
        std::vector<int> digits = {9, 9};
        printDigits(plusOne(digits));
    }

    return 0;
}