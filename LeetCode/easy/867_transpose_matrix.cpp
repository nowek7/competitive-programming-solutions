#include <cassert>
#include <vector>

std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix)
{
  std::vector<std::vector<int>> transposed(matrix.front().size(), std::vector<int>(matrix.size(), 0));
  for (int i = 0; i < matrix.size(); ++i) {
    auto& row = matrix[i];
    for (int j = 0; j < row.size(); ++j) {
      transposed[j][i] = row[j];
    }
  }

  return transposed;
}

int main()
{
  // 867. Transpose Matrix

  {
    std::vector<std::vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
    };
    const std::vector<std::vector<int>> result = transpose(matrix);
    const std::vector<std::vector<int>> expected = {
      {1, 4, 7},
      {2, 5, 8},
      {3, 6, 9}
    };
    for (int i = 0; i < result.size(); ++i) {
      assert(result[i] == expected[i]);
    }
  }

  {
    std::vector<std::vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6}
    };
    const std::vector<std::vector<int>> result = transpose(matrix);
    const std::vector<std::vector<int>> expected = {
      {1, 4},
      {2, 5},
      {3, 6}
    };
    for (int i = 0; i < result.size(); ++i) {
      assert(result[i] == expected[i]);
    }
  }

  return 0;
}
