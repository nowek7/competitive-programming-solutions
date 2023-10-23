#include <iostream>

bool isPowerOfFour(int n)
{
  while (n > 1) {
    if (n % 4 != 0) {
      return false;
    }
    n /= 4;
  }

  return n == 1;
}

bool isPowerOfFour_v2(int n)
{
  return n > 0 && ((n & (n - 1)) == 0) && ((n - 1) % 3 == 0);
}

int main()
{
  // 342. Power of Four

  std::cout << isPowerOfFour_v2(-64) << '\n';
  std::cout << isPowerOfFour_v2(1) << '\n';
  std::cout << isPowerOfFour_v2(16) << '\n';
  std::cout << isPowerOfFour_v2(256) << '\n';
  std::cout << isPowerOfFour_v2(15) << '\n';

  return 0;
}
