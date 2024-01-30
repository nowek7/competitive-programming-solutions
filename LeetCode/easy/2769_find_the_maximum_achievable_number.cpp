#include <cassert>

int theMaximumAchievableX(int num, int t)
{
  return num + t + t;
}

int main()
{
  // 2769. Find the Maximum Achievable Number

  {
    assert(theMaximumAchievableX(4, 1) == 6);
  }

  {
    assert(theMaximumAchievableX(3, 2) == 7);
  }

  return 0;
}
