#include <cassert>
#include <unordered_set>
#include <vector>

std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid)
{
  const int expectedSum = (1 + grid.size() * grid.size()) * 0.5 * (grid.size() * grid.size());

  std::vector<int> result(2);
  std::unordered_set<int> numbers;
  int sum = 0;
  for (auto& row: grid) {
    for (auto i = 0; i < row.size(); ++i) {
      sum += row[i];
      if (numbers.find(row[i]) != numbers.cend()) {
        result[0] = row[i];
      } else {
        numbers.insert(row[i]);
      }
    }
  }

  result[1] = expectedSum - sum + result[0];

  return result;
}

std::vector<int> findMissingAndRepeatedValues_v2(std::vector<std::vector<int>>& grid)
{
  std::vector<int> result(2);
  std::vector<int> frequency(grid.size() * grid.size(), 0);
  for (auto& row: grid) {
    for (auto i = 0; i < row.size(); ++i) {
      frequency[row[i] - 1]++;
      if (frequency[row[i] - 1] == 2) {
        result[0] = row[i];
      }
    }
  }

  for (auto i = 0; i < frequency.size(); ++i) {
    if (frequency[i] == 0) {
      result[1] = i + 1;
      break;
    }
  }

  return result;
}

int main()
{
  // 2965. Find Missing and Repeated Values

  {
    std::vector<std::vector<int>> grid = {
      {1, 3},
      {2, 2}
    };
    std::vector<int> expected = {2, 4};

    {
      std::vector<int> result = findMissingAndRepeatedValues(grid);
      assert(result == expected);
    }
    {
      std::vector<int> result = findMissingAndRepeatedValues_v2(grid);
      assert(result == expected);
    }
  }

  {
    std::vector<std::vector<int>> grid = {
      {9, 1, 7},
      {8, 9, 2},
      {3, 4, 6}
    };
    std::vector<int> expected = {9, 5};

    {
      std::vector<int> result = findMissingAndRepeatedValues(grid);
      assert(result == expected);
    }
    {
      std::vector<int> result = findMissingAndRepeatedValues_v2(grid);
      assert(result == expected);
    }
  }

  return 0;
}
