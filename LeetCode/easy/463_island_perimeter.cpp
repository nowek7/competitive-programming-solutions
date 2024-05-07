#include <cassert>
#include <vector>

int islandPerimeter(std::vector<std::vector<int>>& grid)
{
  int perimeter = 0;

  const int numRows = grid.size();
  const int numCols = grid[0].size();
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      if (grid[i][j] == 0) {
        continue;
      }

      perimeter += 4;
      if (i > 0 && grid[i - 1][j] == 1) {
        perimeter -= 2;
      }

      if (j > 0 && grid[i][j - 1] == 1) {
        perimeter -= 2;
      }
    }
  }

  return perimeter;
}

int main()
{
  // 463. Island Perimeter

  {
    std::vector<std::vector<int>> grid = {
      {0, 1, 0, 0},
      {1, 1, 1, 0},
      {0, 1, 0, 0},
      {1, 1, 0, 0}
    };
    assert(islandPerimeter(grid) == 16);
  }

  {
    std::vector<std::vector<int>> grid = {{1}};
    assert(islandPerimeter(grid) == 4);
  }

  {
    std::vector<std::vector<int>> grid = {
      {1, 0}
    };
    assert(islandPerimeter(grid) == 4);
  }

  return 0;
}