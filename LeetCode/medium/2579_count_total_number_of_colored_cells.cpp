#include <cassert>

long long coloredCells(int n)
{
  return 1 + static_cast<long long>(n) * (n - 1) * 2;
}

long long coloredCells_v2(int n)
{
  long long result = 1;
  long long numCells = 4;
  while (n > 1) {
    result += numCells;
    numCells += 4;
    --n;
  }

  return result;
}

int main()
{
  // 2579. Count Total Number of Colored Cells

  {
    assert(coloredCells(1) == 1);
    assert(coloredCells_v2(1) == 1);
  }

  {
    assert(coloredCells(2) == 5);
    assert(coloredCells_v2(2) == 5);
  }

  {
    assert(coloredCells(3) == 13);
    assert(coloredCells_v2(3) == 13);
  }

  return 0;
}
