#include <cassert>
#include <vector>

int kInversePairs(int n, int k)
{
  const int mod = 1e9 + 7;
  int result = 0;

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));
  for (int i = 0; i <= n; ++i) {
    dp[i][0] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      dp[i][j] = (dp[i - 1][j] + (j > 0 ? dp[i][j - 1] : 0)) % mod;
      dp[i][j] = (dp[i][j] + mod - (j >= i ? dp[i - 1][j - i] : 0)) % mod;
    }
  }

  return dp[n][k];
}

int main()
{
  // 629. K Inverse Pairs Array

  assert(kInversePairs(0, 0) == 1);
  assert(kInversePairs(2, 0) == 1);
  assert(kInversePairs(3, 0) == 1);
  assert(kInversePairs(3, 1) == 2);
  assert(kInversePairs(5, 6) == 20);

  return 0;
}
