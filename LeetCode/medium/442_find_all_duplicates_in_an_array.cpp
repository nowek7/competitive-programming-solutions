#include <cassert>
#include <cmath>
#include <unordered_set>
#include <vector>

std::vector<int> findDuplicates(std::vector<int>& nums)
{
  std::unordered_set<int> uniques;
  std::vector<int> duplicates;

  for (auto num: nums) {
    if (uniques.count(num)) {
      duplicates.push_back(num);
    } else {
      uniques.insert(num);
    }
  }

  return duplicates;
}

std::vector<int> findDuplicates_v2(std::vector<int>& nums)
{
  std::vector<int> duplicates;

  for (int i = 0; i < nums.size(); ++i) {
    int number = std::abs(nums[i]);
    if (nums[number] < 0) {
      duplicates.push_back(number);
    } else {
      nums[number] = -nums[number];
    }
  }

  return duplicates;
}

int main()
{
  // 442. Find All Duplicates in an Array

  {
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    std::vector<int> expected = {2, 3};
    assert(findDuplicates(nums) == expected);
    assert(findDuplicates_v2(nums) == expected);
  }

  {
    std::vector<int> nums = {1, 1, 2};
    std::vector<int> expected = {1};
    assert(findDuplicates(nums) == expected);
    assert(findDuplicates_v2(nums) == expected);
  }

  {
    std::vector<int> nums = {1};
    std::vector<int> expected = {};
    assert(findDuplicates(nums) == expected);
    assert(findDuplicates_v2(nums) == expected);
  }

  return 0;
}