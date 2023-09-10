#include <bits>

#include <iostream>

int hammingDistance(int x, int y)
{
    return std::popcount(static_cast<unsigned int>(x^y));
    // return __builtin_popcount(x^y);
}

int hammingDistance_v2(int x, int y)
{
    int i = x^y;

    // Returns the number of 1 bits in the value || Count hamming distance between number and zero
    i = (i & 0x55555555u) + ((i >> 1) & 0x55555555u);
    i = (i & 0x33333333u) + ((i >> 2) & 0x33333333u);
    i = (i & 0x0f0f0f0fu) + ((i >> 4) & 0x0f0f0f0fu);
    i = (i & 0x00ff00ffu) + ((i >> 8) & 0x00ff00ffu);
    i = (i & 0x0000ffffu) + ((i >> 16) & 0x0000ffffu);
    return i;
}

int main()
{
    // 461. Hamming Distance
    {
        std::cout << hammingDistance(1, 4) << '\n';
    }

    {
        std::cout << hammingDistance(8, 1) << '\n';
    }

    {
        std::cout << hammingDistance_v2(1, 4) << '\n';
    }


    return 0;
}