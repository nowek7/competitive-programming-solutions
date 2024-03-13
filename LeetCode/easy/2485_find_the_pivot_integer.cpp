#include <cassert>

int pivotInteger(int n)
{
  const int totalSum = (1 + n) * n * 0.5;
  for (int i = 1; i <= n; ++i) {
    const int sum = (1 + i) * i * 0.5;
    if (sum + sum == totalSum + i) {
      return i;
    }
  }

  return -1;
}

int main()
{
  // 2485. Find the Pivot Integer

  assert(pivotInteger(1) == 1);
  assert(pivotInteger(8) == 6);
  assert(pivotInteger(4) == -1);
  assert(pivotInteger(999) == -1);
  assert(pivotInteger(100) == -1);

  return 0;
}
