#include <cassert>
#include <vector>

class Solution
{
public:
  int cherryPickup(std::vector<std::vector<int>>& grid)
  {
    const int numRows = grid.size();
    const int numCols = grid[0].size();

    dp = std::vector<std::vector<std::vector<int>>>(
      numRows + 1,
      std::vector<std::vector<int>>(numCols + 1, std::vector<int>(numCols + 1, -1))
    );

    return solve(grid, 0, 0, numCols - 1);
  }

private:
  int solve(std::vector<std::vector<int>>& grid, int rowIdx, int firstRobotColIdx, int secondRobotColIdx)
  {
    if (firstRobotColIdx < 0 || secondRobotColIdx < 0 || firstRobotColIdx >= grid[0].size()
        || secondRobotColIdx >= grid[0].size()) {
      return 0;
    }

    if (rowIdx == grid.size()) {
      return 0;
    }

    if (dp[rowIdx][firstRobotColIdx][secondRobotColIdx] > -1) {
      return dp[rowIdx][firstRobotColIdx][secondRobotColIdx];
    }

    int result = 0;
    result += grid[rowIdx][firstRobotColIdx];
    result += grid[rowIdx][secondRobotColIdx];

    int maxValue = 0;
    for (int i = firstRobotColIdx - 1; i <= firstRobotColIdx + 1; ++i) {
      for (int j = secondRobotColIdx - 1; j <= secondRobotColIdx + 1; ++j) {
        if (i < j) {
          maxValue = std::max(maxValue, solve(grid, rowIdx + 1, i, j));
        }
      }
    }

    result += maxValue;
    dp[rowIdx][firstRobotColIdx][secondRobotColIdx] = result;
    return dp[rowIdx][firstRobotColIdx][secondRobotColIdx];
  }

  std::vector<std::vector<std::vector<int>>> dp;
};

int main()
{
  // 1463. Cherry Pickup II

  {
    std::vector<std::vector<int>> grid = {
      {3, 1, 1},
      {2, 5, 1},
      {1, 5, 5},
      {2, 1, 1}
    };
    assert(Solution().cherryPickup(grid) == 24);
  }

  {
    std::vector<std::vector<int>> grid = {
      {1, 0, 0, 0, 0, 0, 1},
      {2, 0, 0, 0, 0, 3, 0},
      {2, 0, 9, 0, 0, 0, 0},
      {0, 3, 0, 5, 4, 0, 0},
      {1, 0, 2, 3, 0, 0, 6}
    };
    assert(Solution().cherryPickup(grid) == 28);
  }

  return 0;
}
