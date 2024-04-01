#include <cassert>

int countOperations(int num1, int num2)
{
  int numOps = 0;
  while (num1 > 0 && num2 > 0) {
    if (num1 >= num2) {
      num1 -= num2;
    } else {
      num2 -= num1;
    }

    ++numOps;
  }

  return numOps;
}

int main()
{
  // 2169. Count Operations to Obtain Zero

  {
    int num1 = 2;
    int num2 = 3;
    assert(countOperations(num1, num2) == 3);
  }

  {
    int num1 = 10;
    int num2 = 10;
    assert(countOperations(num1, num2) == 1);
  }

  {
    int num1 = 10000;
    int num2 = 1;
    assert(countOperations(num1, num2) == 10000);
  }

  return 0;
}