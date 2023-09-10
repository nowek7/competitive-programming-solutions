#include <iostream>

int numberOfSteps(int num)
{
  int steps = 0;
  while (num > 0) {
    if ((num & 1) == 0) {
      num = num >> 1;
    } else {
      --num;
    }
    steps++;
  }

  return steps;
}

int main()
{
  std::cout << numberOfSteps(15) << '\n';

  return 0;
}