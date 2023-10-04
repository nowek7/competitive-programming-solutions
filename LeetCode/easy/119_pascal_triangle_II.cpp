#include <iostream>
#include <vector>

std::vector<int> getRow(int rowIndex)
{
  if (rowIndex == 0) {
    return {1};
  } else if (rowIndex == 1) {
    return {1, 1};
  } else {
    std::vector<int> row = {1, 1};
    for (int i = 2; i <= rowIndex; ++i) {
      std::vector<int> prevRow(i + 1, 1);
      for (int j = 1; j < row.size(); ++j) {
        prevRow[j] = row.at(j - 1) + row.at(j);
      }
      row = prevRow;
    }
    return row;
  }
}

std::vector<int> getRow_v2(int rowIndex)
{
  std::vector<int> prevRow = {1};
  if (rowIndex > 0) {
    prevRow = {1, 1};
  }

  for (int i = 1; i <= rowIndex; ++i) {
    std::vector<int> row(i + 1, 1);
    for (int j = 1; j < i; ++j) {
      row[j] = prevRow[j - 1] + prevRow[j];
    }
    prevRow = row;
  }
  return prevRow;
}

void printPascalTriangleRow(const std::vector<int>& row)
{
  std::cout << '[';
  if (!row.empty()) {
    for (auto i = 0; i < row.size() - 1; ++i) {
      std::cout << row.at(i) << ", ";
    }
    std::cout << *row.rbegin();
  }
  std::cout << ']';
}

int main()
{
  // 119. Pascal's Triangle II
  {
    int rowIndex = 0;
    printPascalTriangleRow(getRow(rowIndex));
    std::cout << '\n';
  }

  {
    int rowIndex = 1;
    printPascalTriangleRow(getRow(rowIndex));
    std::cout << '\n';
  }

  {
    int rowIndex = 2;
    printPascalTriangleRow(getRow(rowIndex));
    std::cout << '\n';
  }

  {
    int rowIndex = 3;
    printPascalTriangleRow(getRow(rowIndex));
    std::cout << '\n';
  }

  {
    int rowIndex = 4;
    printPascalTriangleRow(getRow(rowIndex));
    std::cout << '\n';
  }

  return 0;
}