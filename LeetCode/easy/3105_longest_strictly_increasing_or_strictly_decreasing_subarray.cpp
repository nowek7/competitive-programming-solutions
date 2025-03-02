#include <cassert>
#include <vector>

int longestMonotonicSubarray(std::vector<int>& nums)
{
  int maxLength = 1;

  int leftDecreasing = 0;
  int leftIncreasing = 0;
  for (int right = 1; right < nums.size(); ++right) {
    if (nums[right] >= nums[right - 1]) {
      leftDecreasing = right;
    }

    if (nums[right] <= nums[right - 1]) {
      leftIncreasing = right;
    }

    maxLength = std::max(maxLength, right - std::min(leftDecreasing, leftIncreasing) + 1);
  }

  return maxLength;
}

int main()
{
  // 3105. Longest Strictly Increasing or Strictly Decreasing Subarray

  {
    std::vector<int> nums = {1, 4, 3, 3, 2};
    assert(longestMonotonicSubarray(nums) == 2);
  }

  {
    std::vector<int> nums = {3, 3, 3};
    assert(longestMonotonicSubarray(nums) == 1);
  }

  {
    std::vector<int> nums = {1};
    assert(longestMonotonicSubarray(nums) == 1);
  }

  {
    std::vector<int> nums = {1,  2,  3,  4,  5, 6, 7,  19, 20, 21, 22, 23, 24, 25, 26,
                             27, 28, 29, 30, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    assert(longestMonotonicSubarray(nums) == 19);
  }

  return 0;
}
