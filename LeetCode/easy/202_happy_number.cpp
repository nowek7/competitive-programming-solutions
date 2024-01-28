#include <cassert>

bool isHappy(int n)
{
  auto sumOfSquaresOfDigitsNumber = [](int number) {
    int sum = 0;
    while (number > 0) {
      const int digit = number % 10;
      number /= 10;
      sum += digit * digit;
    }

    return sum;
  };

  while (true) {
    if (n == 1 || n == 7) {
      return true;
    }

    if (n < 10) {
      return false;
    }

    n = sumOfSquaresOfDigitsNumber(n);
  }

  return true;
}

int main()
{
  // 88. Happy Number

  assert(isHappy(1) == true);
  assert(isHappy(2) == false);
  assert(isHappy(7) == true);
  assert(isHappy(19) == true);

  return 0;
}
