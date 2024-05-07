#include <algorithm>
#include <cassert>

int tribonacci(int n)
{
  if (n == 0) {
    return 0;
  }

  if (n <= 2) {
    return 1;
  }

  int prev = 0;
  int curr = 1;
  int next = 1;
  for (int i = 3; i <= n; ++i) {
    int tmp = next;
    next = prev + curr + next;
    std::swap(tmp, curr);
    std::swap(tmp, prev);
  }

  return next;
}

int main()
{
  // 1137. N-th Tribonacci Number

  {
    assert(tribonacci(4) == 4);
  }

  {
    assert(tribonacci(25) == 1389537);
  }

  return 0;
}
