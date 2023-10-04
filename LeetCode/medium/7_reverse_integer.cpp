#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int reverse(int x)
{
  int rev = 0;
  while (x != 0) {
    if (rev > INT_MAX * 0.1) {
      return 0;
    }
    if (rev < INT_MIN * 0.1) {
      return 0;
    }

    rev = (rev * 10) + (x % 10);
    x /= 10;
  }

  return rev;
}

int main()
{
  // 7. Reverse Integer
  {
    int x = 123;
    std::cout << reverse(x) << '\n';
  }

  {
    int x = -123;
    std::cout << reverse(x) << '\n';
  }

  {
    int x = 120;
    std::cout << reverse(x) << '\n';
  }

  {
    int x = -120;
    std::cout << reverse(x) << '\n';
  }

  return 0;
}