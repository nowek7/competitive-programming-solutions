#include <cassert>

int sum(int num1, int num2)
{
  return num1 + num2;
}

int main()
{
  // 2235. Add Two Integers

  assert(sum(1, 2) == 3);
  assert(sum(100, 0) == 100);
  assert(sum(100, -100) == 0);
}