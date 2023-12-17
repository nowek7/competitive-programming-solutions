#include <cassert>
#include <vector>

int numSpecial(std::vector<std::vector<int>>& mat)
{
  const int numRows = mat.size();
  const int numCols = mat[0].size();

  std::vector<int> rows(numRows);
  std::vector<int> cols(numCols);
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      rows[i] += mat[i][j];
      cols[j] += mat[i][j];
    }
  }

  int result = 0;
  for (int i = 0; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) {
        ++result;
      }
    }
  }

  return result;
}

int main()
{
  // 1582. Special Positions in a Binary Matrix

  {
    std::vector<std::vector<int>> matrix = {
      {1, 0, 0},
      {0, 0, 1},
      {1, 0, 0}
    };
    assert(numSpecial(matrix) == 1);
  }

  {
    std::vector<std::vector<int>> matrix = {
      {1, 0, 0},
      {0, 1, 0},
      {0, 0, 1}
    };
    assert(numSpecial(matrix) == 3);
  }

  return 0;
}