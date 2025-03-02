#include <cassert>
#include <vector>

int countGoodStrings(int low, int high, int zero, int one)
{
  const int mod = 1e9 + 7;
  std::vector<int> dp(high + 1);
  dp[0] = 1;

  for (int i = 1; i <= high; ++i) {
    if (i >= zero) {
      dp[i] += dp[i - zero];
    }

    if (i >= one) {
      dp[i] += dp[i - one];
    }

    dp[i] %= mod;
  }

  int result = 0;
  for (int i = low; i <= high; ++i) {
    result += dp[i];
    result %= mod;
  }

  return result;
}

int main()
{
  // 2466. Count Ways To Build Good Strings

  {
    int low = 3;
    int high = 3;
    int zero = 1;
    int one = 1;
    assert(countGoodStrings(low, high, zero, one) == 8);
  }

  {
    int low = 2;
    int high = 3;
    int zero = 1;
    int one = 2;
    assert(countGoodStrings(low, high, zero, one) == 5);
  }

  return 0;
}
