#include <algorithm>
#include <cassert>
#include <climits>
#include <vector>

int minFallingPathSum(std::vector<std::vector<int>>& matrix)
{
  const int numRows = matrix.size();
  const int numCols = matrix[0].size();
  std::vector<std::vector<int>> sums(numRows, std::vector<int>(numCols, 0));

  for (int i = 0; i < numCols; ++i) {
    sums[0][i] = matrix[0][i];
  }

  for (int i = 1; i < numRows; ++i) {
    for (int j = 0; j < numCols; ++j) {
      int left = INT_MAX;
      int right = INT_MAX;
      int center = matrix[i][j] + sums[i - 1][j];

      if (j > 0) {
        left = matrix[i][j] + sums[i - 1][j - 1];
      }
      if (j < numCols - 1) {
        right = matrix[i][j] + sums[i - 1][j + 1];
      }

      sums[i][j] = std::min(center, std::min(left, right));
    }
  }

  const auto lastSums = sums.back();
  return *std::min_element(lastSums.begin(), lastSums.end());
}

int main()
{
  // 931. Minimum Falling Path Sum

  {
    std::vector<std::vector<int>> matrix = {
      {2, 1, 3},
      {6, 5, 4},
      {7, 8, 9}
    };
    assert(minFallingPathSum(matrix) == 13);
  }

  {
    std::vector<std::vector<int>> matrix = {
      {-19, 57},
      {-40, -5}
    };
    assert(minFallingPathSum(matrix) == -59);
  }

  return 0;
}
