#include <cassert>
#include <iostream>
#include <map>
#include <vector>

std::vector<std::vector<int>> findMatrix(std::vector<int>& nums)
{
  std::map<int, int> numToCount;

  int maxCount = 0;
  for (const auto& num: nums) {
    maxCount = std::max(maxCount, ++numToCount[num]);
  }

  std::vector<std::vector<int>> arr;
  arr.reserve(maxCount);

  for (auto& [num, count]: numToCount) {
    for (int i = 0; i < count; ++i) {
      if (i >= arr.size()) {
        arr.emplace_back();
      }

      arr[i].push_back(num);
    }
  }

  return arr;
}

void print(std::vector<std::vector<int>>& matrix)
{
  if (!matrix.empty()) {
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[i].size() - 1; ++j) {
        std::cout << matrix[i][j] << " ";
      }
      std::cout << matrix[i].back() << '\n';
    }
  }
}

int main()
{
  // 2610. Convert an Array Into a 2D Array With Conditions

  {
    std::vector<int> nums = {1, 3, 4, 1, 2, 3, 1};
    std::vector<std::vector<int>> expected = {
      {1, 2, 3, 4},
      {1, 3},
      {1}
    };
    std::vector<std::vector<int>> result = findMatrix(nums);
    assert(findMatrix(nums) == expected);
  }

  {
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<std::vector<int>> result = findMatrix(nums);
    std::vector<std::vector<int>> expected = {
      {1, 2, 3, 4}
    };
    assert(findMatrix(nums) == expected);
  }

  return 0;
}
