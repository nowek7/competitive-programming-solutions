#include <iostream>
#include <vector>

int uniquePaths(int m, int n)
{
  if (m == 1 || n == 1) {
    return 1;
  }

  std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));
  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }

  return dp[m - 1][n - 1];

  // auto factorial = [](int num) {
  //   int result = 1;
  //   for (int i = 1; i <= num; ++i) {
  //     result *= i;
  //   }

  //   return result;
  // };

  // return factorial(m + n - 2) / (factorial(n - 1) * factorial(m - 1));
}

int main()
{
  {
    std::cout << uniquePaths(6, 6) << '\n';
  }

  return 0;
}