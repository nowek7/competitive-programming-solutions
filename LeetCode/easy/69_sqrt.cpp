#include <cmath>
#include <iostream>
#include <string>

int mySqrt(int x)
{
  if (x <= 1) {
    return x;
  }

  // Newton method
  unsigned int x0 = x * 0.5;
  unsigned int x1 = 0.5 * (x0 + (x / x0));
  while (x1 < x0) {
    x0 = x1;
    x1 = 0.5 * (x0 + (x / x0));
  }

  return x0;
}

int mySqrt_v2(int x)
{
  if (x == 0) {
    return x;
  }

  int left = 1;
  int right = x;
  while (left <= right) {
    int m = left + (right - left) * 0.5;
    if (m == (x / m)) {
      return m;
    } else if ((x / m) < m) {
      right = m - 1;
    } else if ((x / m) > m) {
      left = m + 1;
    }
  }

  return right;
}

int main()
{
  // 69. Sqrt(x)
  {
    int x = 4;
    std::cout << mySqrt(x) << '\n';
  }

  {
    int x = 8;
    std::cout << mySqrt(x) << '\n';
  }

  {
    int x = 10;
    std::cout << mySqrt(x) << '\n';
  }

  {
    int x = 5;
    std::cout << mySqrt(x) << '\n';
  }

  {
    int x = 25;
    std::cout << mySqrt_v2(x) << '\n';
  }

  return 0;
}
