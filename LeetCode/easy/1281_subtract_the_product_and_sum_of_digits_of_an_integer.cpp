#include <cassert>

int subtractProductAndSum(int n)
{
  int product = 1;
  int sum = 0;
  while (n > 0) {
    const auto rem = n % 10;
    sum += rem;
    product *= rem;

    n /= 10;
  }

  return product - sum;
}

int main()
{
  // 1281. Subtract the Product and Sum of Digits of an Integer

  {
    int n = 234;
    assert(subtractProductAndSum(n) == 15);
  }

  {
    int n = 4421;
    assert(subtractProductAndSum(n) == 21);
  }

  return 0;
}