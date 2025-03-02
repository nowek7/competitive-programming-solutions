#include <cassert>
#include <limits>
#include <numeric>
#include <vector>

long long gridGame(std::vector<std::vector<int>>& grid)
{
  long long firstSum = std::accumulate(grid[0].cbegin(), grid[0].cend(), 0ll);
  long long secondSum = 0ll;

  long long result = std::numeric_limits<long long>::max();
  for (auto i = 0; i < grid[0].size(); ++i) {
    firstSum -= grid[0][i];
    result = std::min(result, std::max(firstSum, secondSum));
    secondSum += grid[1][i];
  }

  return result;
}

int main()
{
  // 2017. Grid Game

  {
    std::vector<std::vector<int>> grid = {
      {2, 5, 4},
      {1, 5, 1}
    };
    assert(gridGame(grid) == 4);
  }

  {
    std::vector<std::vector<int>> grid = {
      {3, 3, 1},
      {8, 5, 2}
    };
    assert(gridGame(grid) == 4);
  }

  {
    std::vector<std::vector<int>> grid = {
      {1, 3, 1, 15},
      {1, 3, 3,  1}
    };
    assert(gridGame(grid) == 7);
  }

  return 0;
}