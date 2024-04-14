#include <cassert>
#include <cmath>
#include <iostream>

bool checkPerfectNumber(int num)
{
  int primes[8] {2, 3, 5, 7, 13, 17, 19, 31};
  for (int i = 0; i < 8; ++i) {
    long long number = std::pow(2, primes[i] - 1) * (std::pow(2, primes[i]) - 1);
    if (number == num) {
      return true;
    }
  }

  return false;
}

int main()
{
  // 507. Perfect Number

  {
    int num = 28;
    assert(checkPerfectNumber(num) == true);
  }

  {
    int num = 7;
    assert(checkPerfectNumber(num) == false);
  }

  return 0;
}