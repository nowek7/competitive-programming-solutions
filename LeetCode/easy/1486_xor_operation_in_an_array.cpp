#include <cassert>

int xorOperation(int n, int start)
{
  int result = start;
  for (int i = 1; i < n; ++i) {
    result ^= (start + (2 * i));
  }

  return result;
}

int main()
{
  // 1486. XOR Operation in an Array

  {
    int n = 5;
    int start = 0;
    assert(xorOperation(n, start) == 8);
  }

  {
    int n = 4;
    int start = 3;
    assert(xorOperation(n, start) == 8);
  }

  return 0;
}