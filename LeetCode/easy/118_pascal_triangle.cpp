#include <iostream>
#include <vector>

std::vector<std::vector<int>> generate(int numRows)
{
  if (numRows == 1) {
    return {{1}};
  } else if (numRows == 2) {
    return {
      {1},
      {1, 1}
    };
  } else {
    std::vector<std::vector<int>> result = {
      {1},
      {1, 1}
    };
    for (int i = 2; i < numRows; ++i) {
      std::vector<int> row = {1};
      const auto& prevRow = result.at(i - 1);
      for (int j = 1; j < prevRow.size(); ++j) {
        row.emplace_back(prevRow.at(j - 1) + prevRow.at(j));
      }
      row.emplace_back(1);
      result.push_back(row);
    }

    return result;
  }
}

std::vector<std::vector<int>> generate_v2(int numRows)
{
  std::vector<std::vector<int>> rows = {{1}};
  if (numRows > 1) {
    rows.push_back({1, 1});
  }

  for (int i = 2; i < numRows; ++i) {
    std::vector<int> row(i + 1, 1);
    for (int j = 1; j < i; ++j) {
      row[j] = rows[i - 1][j - 1] + rows[i - 1][j];
    }
    rows.push_back(row);
  }
  return rows;
}

void printNRowsPascalTraingle(const std::vector<std::vector<int>>&& rows)
{
  if (rows.empty()) {
    return;
  }

  auto printRow = [](const auto& row) {
    std::cout << '[';
    if (!row.empty()) {
      for (auto i = 0; i < row.size() - 1; ++i) {
        std::cout << row.at(i) << ", ";
      }
      std::cout << *row.rbegin();
    }
    std::cout << ']';
  };

  for (auto r = 0; r < rows.size() - 1; ++r) {
    const auto& row = rows.at(r);
    printRow(row);
    std::cout << ",";
  }
  const auto& lastRow = *rows.rbegin();
  printRow(lastRow);
  std::cout << '\n';
}

int main()
{
  // 118. Pascal's Triangle
  {
    int numRows = 1;
    printNRowsPascalTraingle(generate(numRows));
  }

  {
    int numRows = 2;
    printNRowsPascalTraingle(generate(numRows));
  }

  {
    int numRows = 3;
    printNRowsPascalTraingle(generate(numRows));
  }

  {
    int numRows = 4;
    printNRowsPascalTraingle(generate(numRows));
  }

  {
    int numRows = 5;
    printNRowsPascalTraingle(generate(numRows));
  }

  return 0;
}