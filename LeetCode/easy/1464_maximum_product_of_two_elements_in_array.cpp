#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>

int maxProduct(std::vector<int>& nums)
{
  std::sort(nums.begin(), nums.end());
  return (nums[nums.size() - 2] - 1) * (nums.back() - 1);
}

int maxProduct_v2(std::vector<int>& nums)
{
  if (nums.size() == 2) {
    return (nums[0] - 1) * (nums[1] - 1);
  }

  std::pair<int, int> maxElements = {nums[0], nums[1]};
  for (int i = 2; i < nums.size(); ++i) {
    if (maxElements.first <= maxElements.second) {
      maxElements.first = std::max(maxElements.first, nums[i]);
    } else {
      maxElements.second = std::max(maxElements.second, nums[i]);
    }
  }

  return (maxElements.first - 1) * (maxElements.second - 1);
}

int main()
{
  // 1464. Maximum Product of Two Elements in an Array

  {
    std::vector<int> nums = {3, 4, 5, 2};
    assert(maxProduct(nums) == 12);
  }

  {
    std::vector<int> nums = {1, 5, 4, 5};
    assert(maxProduct(nums) == 16);
  }

  {
    std::vector<int> nums = {3, 7};
    assert(maxProduct_v2(nums) == 12);
  }

  return 0;
}
