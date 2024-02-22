#include <cassert>

int rangeBitwiseAnd(int left, int right)
{
  int counter = 0;

  while (left < right) {
    left = left >> 1;
    right = right >> 1;
    ++counter;
  }

  return left << counter;
}

int main()
{
  // 201. Bitwise AND of Numbers Range

  {
    int left = 5;
    int right = 7;
    assert(rangeBitwiseAnd(left, right) == 4);
  }

  {
    int left = 0;
    int right = 0;
    assert(rangeBitwiseAnd(left, right) == 0);
  }

  {
    int left = 1;
    int right = 2147483647;
    assert(rangeBitwiseAnd(left, right) == 0);
  }

  return 0;
}
