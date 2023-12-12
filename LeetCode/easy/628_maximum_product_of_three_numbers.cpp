#include <algorithm>
#include <cassert>
#include <vector>

int maximumProduct(std::vector<int>& nums)
{
  const int n = nums.size();
  if (n == 3) {
    return nums[0] * nums[1] * nums[2];
  }

  std::sort(nums.begin(), nums.end());
  if (nums.back() < 0) {
    return nums[n - 1] * nums[n - 2] * nums[n - 3];
  } else if (nums.back() == 0) {
    return 0;
  } else {
    if (nums[0] * nums[1] >= nums[n - 1] * nums[n - 2]) {
      return nums[0] * nums[1] * nums[n - 1];
    } else {
      return nums[n - 1] * std::max(nums[0] * nums[1], nums[n - 2] * nums[n - 3]);
    }
  }
}

int maximumProduct_v2(std::vector<int>& nums)
{
  std::sort(nums.begin(), nums.end());
  const int left = nums[0] * nums[1] * nums[nums.size() - 1];
  const int right = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
  return left >= right ? left : right;
}

int main()
{
  // 628. Maximum Product of Three Numbers

  {
    std::vector<int> nums = {1, 2, 3};
    assert(maximumProduct(nums) == 6);
  }

  {
    std::vector<int> nums = {1, 2, 3, 4};
    assert(maximumProduct(nums) == 24);
  }

  {
    std::vector<int> nums = {-1, -2, -3};
    assert(maximumProduct(nums) == -6);
  }

  {
    std::vector<int> nums = {-1, -2, -3, -5, -10, 1, 4, 8, 3};
    assert(maximumProduct_v2(nums) == 400);
  }

  return 0;
}
