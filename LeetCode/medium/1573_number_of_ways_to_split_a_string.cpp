#include <cassert>

bool canSplit(int number, int target)
{
  if (target < 0 || number < target) {
    return false;
  }

  if (number == target) {
    return true;
  }

  return canSplit(number / 10, target - number % 10) || canSplit(number / 100, target - number % 100)
    || canSplit(number / 1000, target - number % 1000);
}

int punishmentNumber(int n)
{
  int result = 0;

  for (int i = 1; i <= n; ++i) {
    const int number = i * i;
    if (canSplit(number, i)) {
      result += number;
    }
  }

  return result;
}

int main()
{
  // 1573. Number of Ways to Split a String

  {
    int n = 10;
    assert(punishmentNumber(n) == 182);
  }

  {
    int n = 37;
    assert(punishmentNumber(n) == 1478);
  }

  return 0;
}
