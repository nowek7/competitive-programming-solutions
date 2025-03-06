#include <cassert>
#include <vector>

bool isPrime(int n)
{
  if (n <= 1) {
    return false;
  }
  if (n <= 3) {
    return true;
  }
  if (n % 2 == 0 || n % 3 == 0) {
    return false;
  }

  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

std::vector<int> closestPrimes(int left, int right)
{
  if (left <= 2 && right >= 3) {
    return {2, 3};
  }

  std::vector<int> primeNumbers;
  primeNumbers.reserve(right - left);
  for (int num = left; num <= right; ++num) {
    if (isPrime(num)) {
      primeNumbers.push_back(num);
    }
  }

  if (primeNumbers.size() < 2) {
    return {-1, -1};
  }

  int num1 = primeNumbers[0];
  int num2 = primeNumbers[1];
  for (auto i = 2; i < primeNumbers.size(); ++i) {
    if ((primeNumbers[i] - primeNumbers[i - 1]) < (num2 - num1)) {
      num1 = primeNumbers[i - 1];
      num2 = primeNumbers[i];
    }
  }

  return {num1, num2};
}

int main()
{
  // 2523. Closest Prime Numbers in Range

  {
    int left = 10;
    int right = 19;
    std::vector<int> expected = {11, 13};
    auto result = closestPrimes(left, right);
    assert(result == expected);
  }

  {
    int left = 19;
    int right = 31;
    std::vector<int> expected = {29, 31};
    auto result = closestPrimes(left, right);
    assert(result == expected);
  }

  {
    int left = 4;
    int right = 6;
    std::vector<int> expected = {-1, -1};
    auto result = closestPrimes(left, right);
    assert(result == expected);
  }

  return 0;
}
