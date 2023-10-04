#include <algorithm>
#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
{
  int topIdx = 0;
  int bottomIdx = matrix.size() - 1;
  while (topIdx <= bottomIdx) {
    const int idx = topIdx + (bottomIdx - topIdx) / 2;
    auto& row = matrix.at(idx);
    if (row.front() > target) {
      bottomIdx = idx - 1;
    } else if (row.back() < target) {
      topIdx = idx + 1;
    } else {
      return std::binary_search(row.begin(), row.end(), target);
    }
  }

  return false;
}

bool searchMatrix_v2(std::vector<std::vector<int>>& matrix, int target)
{
  int rowIdx = 0;
  int colIdx = matrix.front().size() - 1;

  while (rowIdx < matrix.size() && colIdx >= 0) {
    auto& row = matrix.at(rowIdx);
    if (row.at(colIdx) == target) {
      return true;
    } else if (row.at(colIdx) > target) {
      --colIdx;
    } else {
      ++rowIdx;
    }
  }

  return false;
}

int main()
{
  // 74. Search a 2D Matrix
  {
    std::vector<std::vector<int>> matrix = {
      { 1,  3,  5,  7},
      {10, 11, 16, 20},
      {23, 30, 34, 60}
    };
    std::cout << searchMatrix(matrix, 3) << '\n';
  }

  {
    std::vector<std::vector<int>> matrix = {
      { 1,  3,  5,  7},
      {10, 11, 16, 20},
      {23, 30, 34, 60}
    };
    std::cout << searchMatrix(matrix, 13) << '\n';
  }

  {
    std::vector<std::vector<int>> matrix = {
      {1, 3, 5, 7}
    };
    std::cout << searchMatrix_v2(matrix, 3) << '\n';
  }

  {
    std::vector<std::vector<int>> matrix = {
      { 1,  3,  5,  7},
      {10, 11, 16, 20},
      {23, 30, 34, 60}
    };
    std::cout << searchMatrix_v2(matrix, 13) << '\n';
  }

  return 0;
}