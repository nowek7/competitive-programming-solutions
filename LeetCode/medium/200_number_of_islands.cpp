#include <cassert>
#include <vector>

void walk(
  std::vector<std::vector<char>>& grid,
  std::size_t rowIdx,
  std::size_t colIdx,
  std::vector<std::vector<bool>>& visited
)
{
  if (rowIdx < 0 || rowIdx >= grid.size()) {
    return;
  }

  if (colIdx < 0 || colIdx >= grid[0].size()) {
    return;
  }

  if (visited[rowIdx][colIdx]) {
    return;
  }

  visited[rowIdx][colIdx] = true;
  if (grid[rowIdx][colIdx] == '0') {
    return;
  }

  walk(grid, rowIdx, colIdx + 1, visited);
  walk(grid, rowIdx + 1, colIdx, visited);
  walk(grid, rowIdx, colIdx - 1, visited);
  walk(grid, rowIdx - 1, colIdx, visited);
}

int numIslands(std::vector<std::vector<char>>& grid)
{
  const int numRows = grid.size();
  const int numCols = grid[0].size();
  std::vector<std::vector<bool>> visited(numRows, std::vector<bool>(numCols, false));

  int counter = 0;
  for (auto i = 0; i < numRows; ++i) {
    for (auto j = 0; j < numCols; ++j) {
      if (visited[i][j] || grid[i][j] == '0') {
        visited[i][j] = true;
        continue;
      }

      ++counter;
      walk(grid, i, j, visited);
    }
  }

  return counter;
}

int main()
{
  // 200. Number of Islands

  {
    std::vector<std::vector<char>> grid = {
      {'1', '1', '1', '1', '0'},
      {'1', '1', '0', '1', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '0', '0', '0'}
    };
    assert(numIslands(grid) == 1);
  }

  {
    std::vector<std::vector<char>> grid = {
      {'1', '1', '0', '0', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '1', '0', '0'},
      {'0', '0', '0', '1', '1'}
    };
    assert(numIslands(grid) == 3);
  }

  return 0;
}
