#include <algorithm>
#include <cassert>
#include <climits>
#include <vector>

std::vector<int> findTwoMinElements(const std::vector<int>& row)
{
  int first = INT_MAX;
  int second = INT_MAX;
  for (std::size_t i = 0; i < row.size(); ++i) {
    if (row[i] < first) {
      second = std::exchange(first, row[i]);
    } else if (row[i] < second) {
      second = row[i];
    }
  }

  return {first, second};
}

int minFallingPathSum(std::vector<std::vector<int>>& grid)
{
  for (std::size_t i = 1; i < grid.size(); ++i) {
    auto minElements = findTwoMinElements(grid[i - 1]);
    for (std::size_t j = 0; j < grid[0].size(); ++j) {
      if (grid[i - 1][j] == minElements[0]) {
        grid[i][j] += minElements[1];
      } else {
        grid[i][j] += minElements[0];
      }
    }
  }

  auto lastRow = grid.back();
  return *std::min_element(lastRow.begin(), lastRow.end());
}

int main()
{
  // 1289. Minimum Falling Path Sum II

  {
    std::vector<std::vector<int>> grid = {

    };
    assert(minFallingPathSum(grid) == 13);
  }

  {
    std::vector<std::vector<int>> grid = {{7}};
    assert(minFallingPathSum(grid) == 7);
  }

  return 0;
}
