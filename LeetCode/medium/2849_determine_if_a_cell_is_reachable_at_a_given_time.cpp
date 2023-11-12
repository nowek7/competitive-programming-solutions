#include <cassert>
#include <cmath>

bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
{
  if (sx == fx && sy == fy) {
    return t != 1;
  }

  return std::max(std::abs(sx - fx), std::abs(sy - fy)) <= t;
}

int main()
{
  // 2849. Determine if a Cell Is Reachable at a Given Time

  assert(isReachableAtTime(2, 4, 7, 7, 6) == true);
  assert(isReachableAtTime(3, 1, 7, 3, 3) == false);
  assert(isReachableAtTime(1, 2, 1, 2, 1) == false);
  assert(isReachableAtTime(1, 3, 1, 3, 0) == true);

  return 0;
}