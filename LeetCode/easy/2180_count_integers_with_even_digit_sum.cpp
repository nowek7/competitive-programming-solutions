#include <cassert>
#include <cmath>

int countEven(int num)
{
  auto digitSum = [](int number) {
    int sum = 0;
    while (number > 0) {
      sum += number % 10;
      number /= 10;
    }
    return sum;
  };

  int counter = 0;
  for (int i = 1; i <= num; ++i) {
    int sum = digitSum(i);
    if (sum % 2 == 0) {
      ++counter;
    }
  }

  return counter;
}

int main()
{
  // 2180. Count Integers With Even Digit Sum

  assert(countEven(4) == 2);
  assert(countEven(30) == 14);
}