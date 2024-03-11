#include <cassert>

int countDigits(int num)
{
  const int originalNum = num;
  int counter = 0;
  while (num > 0) {
    int digit = num % 10;
    if (originalNum % digit == 0) {
      ++counter;
    }
    num /= 10;
  }

  return counter;
}

int main()
{
  // 2520. Count the Digits That Divide a Number

  {
    int n = 7;
    assert(countDigits(n) == 1);
  }

  {
    int n = 121;
    assert(countDigits(n) == 2);
  }

  {
    int n = 1248;
    assert(countDigits(n) == 4);
  }

  {
    int n = 121259445;
    assert(countDigits(n) == 4);
  }

  {
    int n = 54;
    assert(countDigits(n) == 0);
  }

  return 0;
}