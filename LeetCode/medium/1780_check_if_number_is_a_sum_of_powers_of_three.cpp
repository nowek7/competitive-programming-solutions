#include <cassert>
#include <cmath>

bool checkPowersOfThree(int n)
{
  int power = 0;
  while (std::pow(3, power) <= n) {
    ++power;
  }

  while (n > 0) {
    if (n >= std::pow(3, power)) {
      n -= std::pow(3, power);
    }

    if (n >= std::pow(3, power)) {
      return false;
    }

    --power;
  }

  return true;
}

bool checkPowersOfThree_v2(int n)
{
  while (n > 0) {
    if (n % 3 == 2) {
      return false;
    }

    n /= 3;
  }

  return true;
}

int main()
{
  // 1780. Check if Number is a Sum of Powers of Three

  {
    assert(checkPowersOfThree(12) == true);
    assert(checkPowersOfThree(91) == true);
    assert(checkPowersOfThree(21) == false);
  }

  {
    assert(checkPowersOfThree_v2(12) == true);
    assert(checkPowersOfThree_v2(91) == true);
    assert(checkPowersOfThree_v2(21) == false);
  }

  return 0;
}
