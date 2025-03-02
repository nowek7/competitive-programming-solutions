#include <cassert>
#include <vector>

int countServers(std::vector<std::vector<int>>& grid)
{
  const int numRows = grid.size();
  const int numCols = grid[0].size();

  std::vector<int> rows(numRows, 0);
  std::vector<int> cols(numCols, 0);

  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      if (grid[i][j] == 1) {
        ++rows[i];
        ++cols[j];
      }
    }
  }

  int result = 0;
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) {
        ++result;
      }
    }
  }

  return result;
}

int main()
{
  // 1267. Count Servers that Communicate

  {
    std::vector<std::vector<int>> grid = {
      {1, 0},
      {0, 1}
    };
    assert(countServers(grid) == 0);
  }

  {
    std::vector<std::vector<int>> grid = {
      {1, 0},
      {1, 1}
    };
    assert(countServers(grid) == 3);
  }

  {
    std::vector<std::vector<int>> grid = {
      {1, 1, 0, 0},
      {0, 0, 1, 0},
      {0, 0, 1, 0},
      {0, 0, 0, 1}
    };
    assert(countServers(grid) == 4);
  }

  return 0;
}
