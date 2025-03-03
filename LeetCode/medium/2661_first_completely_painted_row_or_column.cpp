#include <cassert>
#include <vector>

int firstCompleteIndex(std::vector<int>& arr, std::vector<std::vector<int>>& mat)
{
  const int numRows = mat.size();
  const int numCols = mat.front().size();
  std::vector<int> rows(numRows, 0);
  std::vector<int> cols(numCols, 0);

  std::vector<std::pair<int, int>> cells(numRows * numCols);
  for (auto i = 0; i < numRows; ++i) {
    for (auto j = 0; j < numCols; ++j) {
      cells[mat[i][j] - 1] = std::make_pair(i, j);
    }
  }

  int completeIdx = -1;
  for (auto i = 0; i < arr.size(); ++i) {
    auto [rowIdx, colIdx] = cells[arr[i] - 1];
    ++rows[rowIdx];
    ++cols[colIdx];

    if ((rows[rowIdx] == numCols) || (cols[colIdx] == numRows)) {
      completeIdx = i;
      break;
    }
  }

  return completeIdx;
}

int main()
{
  // 2661. First Completely Painted Row or Column

  {
    std::vector<int> arr = {1, 3, 4, 2};
    std::vector<std::vector<int>> mat = {
      {1, 4},
      {2, 3}
    };
    assert(firstCompleteIndex(arr, mat) == 2);
  }

  {
    std::vector<int> arr = {2, 8, 7, 4, 1, 3, 5, 6, 9};
    std::vector<std::vector<int>> mat = {
      {3, 2, 5},
      {1, 4, 6},
      {8, 7, 9}
    };
    assert(firstCompleteIndex(arr, mat) == 3);
  }

  return 0;
}
