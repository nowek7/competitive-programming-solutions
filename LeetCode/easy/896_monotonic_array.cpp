#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

bool isMonotonic(std::vector<int>& nums)
{
  if (nums.front() >= nums.back()) {
    return std::is_sorted(nums.begin(), nums.end(), std::greater<>());
  } else {
    return std::is_sorted(nums.begin(), nums.end(), std::less<>());
  }
}

bool isMonotonic_v2(std::vector<int>& nums)
{
  auto comp = nums.front() >= nums.back() ?
    [](int lhs, int rhs) {
      return lhs >= rhs;
    } :
    [](int lhs, int rhs) {
      return lhs <= rhs;
    };

  for (int i = 1; i < nums.size(); ++i) {
    if (!comp(nums[i - 1], nums[i])) {
      return false;
    }
  }
  return true;
}

int main()
{
  // 896. Monotonic Array
  {
    std::vector<int> nums = {1, 2, 2, 3};
    assert(isMonotonic(nums) == true);
    assert(isMonotonic(nums) == isMonotonic_v2(nums));
  }

  {
    std::vector<int> nums = {6, 5, 4, 4};
    assert(isMonotonic(nums) == true);
    assert(isMonotonic(nums) == isMonotonic_v2(nums));
  }

  {
    std::vector<int> nums = {1, 3, 2};
    assert(isMonotonic(nums) == false);
    assert(isMonotonic(nums) == isMonotonic_v2(nums));
  }

  return 0;
}