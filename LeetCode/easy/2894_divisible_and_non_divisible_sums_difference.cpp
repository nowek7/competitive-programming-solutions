#include <cassert>

int differenceOfSums(int n, int m)
{
  int num1 = 0;
  int num2 = 0;
  for (int i = 1; i <= n; ++i) {
    if (i % m == 0) {
      num2 += i;
    } else {
      num1 += i;
    }
  }

  return num1 - num2;
}

int main()
{
  // 2894. Divisible and Non-divisible Sums Difference

  {
    int n = 10;
    int m = 3;
    assert(differenceOfSums(n, m) == 19);
  }

  {
    int n = 5;
    int m = 6;
    assert(differenceOfSums(n, m) == 15);
  }

  {
    int n = 5;
    int m = -1;
    assert(differenceOfSums(n, m) == -15);
  }

  return 0;
}