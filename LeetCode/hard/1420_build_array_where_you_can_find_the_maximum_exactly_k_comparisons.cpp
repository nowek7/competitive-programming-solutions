#include <cassert>
#include <vector>

int numOfArrays(int n, int m, int k)
{
  const int mod = 1e9 + 7;

  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(k + 1, 0));
  std::vector<std::vector<int>> prevDp(m + 1, std::vector<int>(k + 1, 0));
  std::vector<std::vector<int>> prefix(m + 1, std::vector<int>(k + 1, 0));
  std::vector<std::vector<int>> prevPrefix(m + 1, std::vector<int>(k + 1, 0));

  for (int i = 1; i <= m; ++i) {
    prevDp[i][1] = 1;
    prevPrefix[i][1] = i;
  }

  for (int i = 2; i <= n; ++i) {
    dp.assign(m + 1, std::vector<int>(k + 1, 0));
    prefix.assign(m + 1, std::vector<int>(k + 1, 0));

    for (int maxNumber = 1; maxNumber <= m; ++maxNumber) {
      for (int cost = 1; cost <= k; ++cost) {
        dp[maxNumber][cost] = (static_cast<long long>(maxNumber) * prevDp[maxNumber][cost]) % mod;

        if (maxNumber > 1 && cost > 1) {
          dp[maxNumber][cost] = (dp[maxNumber][cost] + prevPrefix[maxNumber - 1][cost - 1]) % mod;
        }

        prefix[maxNumber][cost] = (prefix[maxNumber - 1][cost] + dp[maxNumber][cost]) % mod;
      }
    }

    prevDp = dp;
    prevPrefix = prefix;
  }

  return prefix[m][k];
}

int main()
{
  // 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons

  {
    assert(6 == numOfArrays(2, 3, 1));
  }

  {
    assert(0 == numOfArrays(5, 2, 3));
  }

  {
    assert(1 == numOfArrays(9, 1, 1));
  }

  return 0;
}
