#include <cassert>

int sumOfMultiples(int n)
{
  auto isDivisibleByThree = [](int number) {
    return number % 3 == 0;
  };

  auto isDivisibleByFive = [](int number) {
    return number % 5 == 0;
  };

  auto isDivisibleBySeven = [](int number) {
    return number % 7 == 0;
  };

  int sum = 0;
  for (auto i = 1; i <= n; ++i) {
    if (isDivisibleByThree(i)) {
      sum += i;
    } else if (isDivisibleByFive(i)) {
      sum += i;
    } else if (isDivisibleBySeven(i)) {
      sum += i;
    }
  }

  return sum;
}

int main()
{
  // 2652. Sum Multiples

  {
    int n = 7;
    assert(sumOfMultiples(n) == 21);
  }

  {
    int n = 10;
    assert(sumOfMultiples(n) == 40);
  }

  {
    int n = 9;
    assert(sumOfMultiples(n) == 30);
  }

  return 0;
}