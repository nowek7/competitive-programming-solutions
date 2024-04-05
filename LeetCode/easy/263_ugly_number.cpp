#include <cassert>

bool isUgly(int n)
{
  if (n < 1) {
    return false;
  }

  auto divByNumber = [](int dividend, int divisor) {
    if (dividend % divisor == 0) {
      dividend /= divisor;
    }
    return dividend;
  };

  while (n > 1) {
    int old = n;

    n = divByNumber(n, 2);
    n = divByNumber(n, 3);
    n = divByNumber(n, 5);
    if (n == old) {
      return false;
    }
  }
  return true;
}

int main()
{
  // 263. Ugly Number

  assert(isUgly(6) == true);
  assert(isUgly(1) == true);
  assert(isUgly(14) == false);
  assert(isUgly(1024) == true);
  assert(isUgly(-1024) == false);
  assert(isUgly(0) == false);

  return 0;
}
