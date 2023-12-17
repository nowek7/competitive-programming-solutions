#include <cassert>
#include <vector>

std::vector<std::vector<int>> onesMinusZeros(std::vector<std::vector<int>>& grid)
{
  const int numRows = grid.size();
  const int numCols = grid.front().size();

  std::vector<int> rows(numRows, 0);
  std::vector<int> cols(numCols, 0);
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      if (grid[i][j] == 1) {
        ++rows[i];
        ++cols[j];
      } else {
        --rows[i];
        --cols[j];
      }
    }
  }

  std::vector<std::vector<int>> diff(numRows, std::vector<int>(numCols, 0));
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      diff[i][j] = rows[i] + cols[j];
    }
  }

  return diff;
}

int main()
{
  // 2482. Difference Between Ones and Zeros in Row and Column

  {
    std::vector<std::vector<int>> matrix = {
      {0, 1, 1},
      {1, 0, 1},
      {0, 0, 1}
    };
    std::vector<std::vector<int>> diff = {
      { 0,  0, 4},
      { 0,  0, 4},
      {-2, -2, 2}
    };

    assert(onesMinusZeros(matrix) == diff);
  }

  {
    std::vector<std::vector<int>> matrix = {
      {1, 1, 1},
      {1, 1, 1}
    };
    std::vector<std::vector<int>> diff = {
      {5, 5, 5},
      {5, 5, 5}
    };

    assert(onesMinusZeros(matrix) == diff);
  }

  return 0;
}
