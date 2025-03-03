#include <cassert>
#include <vector>

int walk(std::vector<std::vector<int>>& grid, int x, int y)
{
  int numFish = 0;

  if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
    return numFish;
  }

  if (grid[x][y] == 0) {
    return numFish;
  }

  numFish += grid[x][y];
  grid[x][y] = 0;
  numFish += walk(grid, x, y - 1);
  numFish += walk(grid, x + 1, y);
  numFish += walk(grid, x, y + 1);
  numFish += walk(grid, x - 1, y);

  return numFish;
}

int findMaxFish(std::vector<std::vector<int>>& grid)
{
  const int numRows = grid.size();
  const int numCols = grid[0].size();

  int maxFish = 0;
  for (auto i = 0; i < numRows; ++i) {
    for (auto j = 0; j < numCols; ++j) {
      int numFish = walk(grid, i, j);
      maxFish = std::max(maxFish, numFish);
    }
  }

  return maxFish;
}

int main()
{
  // 2658. Maximum Number of Fish in a Grid

  {
    std::vector<std::vector<int>> grid = {
      {0, 2, 1, 0},
      {4, 0, 0, 3},
      {1, 0, 0, 4},
      {0, 3, 2, 0}
    };
    assert(findMaxFish(grid) == 7);
  }

  {
    std::vector<std::vector<int>> grid = {
      {1, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 1}
    };
    assert(findMaxFish(grid) == 1);
  }

  return 0;
}
