#include <iostream>

bool isPowerOfTwo(int n)
{
  return (n > 0) && (!(n & (n - 1)));
}

int main()
{
  // 231. Power of Two
  {
    int n = 1;
    std::cout << isPowerOfTwo(n) << '\n';
  }

  {
    int n = -128;
    std::cout << isPowerOfTwo(n) << '\n';
  }

  {
    int n = 16;
    std::cout << isPowerOfTwo(n) << '\n';
  }

  {
    int n = -2147483648;
    std::cout << isPowerOfTwo(n) << '\n';
  }

  {
    int n = 2147483646;
    std::cout << isPowerOfTwo(n) << '\n';
  }

  return 0;
}