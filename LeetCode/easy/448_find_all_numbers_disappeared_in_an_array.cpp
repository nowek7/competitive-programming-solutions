#include <cassert>
#include <iostream>
#include <vector>

std::vector<int> findDisappearedNumbers(std::vector<int>& nums)
{
  std::vector<bool> visited(nums.size(), false);
  for (int i = 0; i < nums.size(); ++i) {
    visited[nums[i] - 1] = true;
  }

  std::vector<int> missing;
  for (int i = 0; i < visited.size(); ++i) {
    if (!visited[i]) {
      missing.push_back(i + 1);
    }
  }

  return missing;
}

int main()
{
  // 448. Find All Numbers Disappeared in an Array

  {
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    std::vector<int> expected = {5, 6};
    assert(findDisappearedNumbers(nums) == expected);
  }

  {
    std::vector<int> nums = {1, 1};
    std::vector<int> expected = {2};
    assert(findDisappearedNumbers(nums) == expected);
  }

  return 0;
}