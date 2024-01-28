#include <cassert>
#include <unordered_map>
#include <vector>

int numSubmatrixSumTarget(std::vector<std::vector<int>>& matrix, int target)
{
  const int numRows = matrix.size();
  const int numCols = matrix[0].size();

  for (int i = 0; i < numRows; ++i) {
    for (int j = 1; j < numCols; ++j) {
      matrix[i][j] += matrix[i][j - 1];
    }
  }

  int result = 0;
  for (int i = 0; i < numCols; ++i) {
    for (int j = i; j < numCols; ++j) {
      int subMatrixSum = 0;

      std::unordered_map<int, int> countOfsubMatrixSum = {
        {0, 1}
      };
      for (int k = 0; k < numRows; ++k) {
        int prefSum = i == 0 ? 0 : matrix[k][i - 1];
        subMatrixSum += matrix[k][j] - prefSum;
        if (countOfsubMatrixSum.count(subMatrixSum - target)) {
          result += countOfsubMatrixSum[subMatrixSum - target];
        }

        ++countOfsubMatrixSum[subMatrixSum];
      }
    }
  }

  return result;
}

int main()
{
  // 1074. Number of Submatrices That Sum to Target

  {
    std::vector<std::vector<int>> matrix = {
      {0, 1, 0},
      {1, 1, 1},
      {0, 1, 0}
    };
    assert(numSubmatrixSumTarget(matrix, 0) == 4);
  }

  {
    std::vector<std::vector<int>> matrix = {
      { 1, -1},
      {-1,  1}
    };
    assert(numSubmatrixSumTarget(matrix, 0) == 5);
  }

  {
    std::vector<std::vector<int>> matrix = {{904}};
    assert(numSubmatrixSumTarget(matrix, 0) == 0);
  }

  return 0;
}
