#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

int minimumOneBitOperations(int n)
{
  if (n < 2) {
    return n;
  }

  const int power = std::floor(std::log2(n));
  int numOps = (1 << (power + 1)) - 1;

  return numOps - minimumOneBitOperations(n ^ (1 << power));
}

int minimumOneBitOperations_v2(int n)
{
  if (n < 2) {
    return n;
  }

  std::vector<int> memOps(n + 1, INT_MIN);
  memOps[1] = 1;

  int numOps = 0;
  for (int i = 2, p = 2; i <= n; ++i) {
    if ((i & (i - 1)) == 0) {
      memOps[i] = memOps[i / 2] + i;
      p = i;
    } else {
      memOps[i] = memOps[p] + memOps[(i ^ p)];
    }
  }

  std::cout << memOps.back() << '\n';
  return memOps.back();
}

int main()
{
  // 1611. Minimum One Bit Operations to Make Integers Zero

  {
    int n = 2;
    std::cout << minimumOneBitOperations(n) << '\n';
  }

  {
    int n = 4;
    std::cout << minimumOneBitOperations(n) << '\n';
  }

  {
    int n = 15;
    std::cout << minimumOneBitOperations(n) << '\n';
  }

  return 0;
}