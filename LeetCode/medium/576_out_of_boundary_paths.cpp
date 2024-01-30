#include <cassert>
#include <vector>

const int mod = 1e9 + 7;
std::vector<std::vector<std::vector<int>>> g_dp;

int solve(int n, int m, int maxMove, int startRow, int startColumn)
{
  if (startColumn < 0 || startColumn >= n) {
    return 1;
  }
  if (startRow < 0 || startRow >= m) {
    return 1;
  }
  if (maxMove == 0) {
    return 0;
  }

  if (g_dp[startRow][startColumn][maxMove] != -1) {
    return g_dp[startRow][startColumn][maxMove];
  }

  int up = solve(n, m, maxMove - 1, startRow - 1, startColumn);
  int down = solve(n, m, maxMove - 1, startRow + 1, startColumn);
  int left = solve(n, m, maxMove - 1, startRow, startColumn - 1);
  int right = solve(n, m, maxMove - 1, startRow, startColumn + 1);

  g_dp[startRow][startColumn][maxMove] = ((up + down) % mod + (left + right) % mod) % mod;
  return g_dp[startRow][startColumn][maxMove];
}

int findpaths(int m, int n, int maxMove, int startRow, int startColumn)
{
  g_dp =
    std::vector<std::vector<std::vector<int>>>(m, std::vector<std::vector<int>>(n, std::vector<int>(maxMove + 1, -1)));
  const int result = solve(n, m, maxMove, startRow, startColumn);

  return result;
}

int main()
{
  // 576. Out of Boundary Paths

  {
    int m = 2;
    int n = 2;
    int maxMove = 2;
    int startRow = 0;
    int startColumn = 0;
    assert(findpaths(m, n, maxMove, startRow, startColumn) == 6);
  }

  {
    int m = 1;
    int n = 3;
    int maxMove = 3;
    int startRow = 0;
    int startColumn = 1;
    assert(findpaths(m, n, maxMove, startRow, startColumn) == 12);
  }

  return 0;
}
