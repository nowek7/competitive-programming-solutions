#include <algorithm>
#include <cassert>
#include <vector>

bool containsDuplicate(std::vector<int>& nums)
{
  std::sort(nums.begin(), nums.end());
#pragma unroll
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i - 1] == nums[i]) {
      return true;
    }
  }
  return false;
}

int main()
{
  // 217. Contains Duplicate

  {
    std::vector<int> nums = {1, 2, 3, 1};
    assert(containsDuplicate(nums) == true);
  }

  {
    std::vector<int> nums = {1, 2, 3, 4};
    assert(containsDuplicate(nums) == false);
  }

  {
    std::vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    assert(containsDuplicate(nums) == true);
  }

  return 0;
}
