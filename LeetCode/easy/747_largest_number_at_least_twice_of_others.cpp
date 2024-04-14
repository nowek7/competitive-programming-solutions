#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int dominantIndex(std::vector<int>& nums)
{
  int maxIdx = 0;
  int secondMaxIdx = 1;
  if (nums[0] < nums[1]) {
    maxIdx = 1;
    secondMaxIdx = 0;
  }

  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] > nums[maxIdx]) {
      secondMaxIdx = maxIdx;
      maxIdx = i;
    } else if (nums[i] > nums[secondMaxIdx]) {
      secondMaxIdx = i;
    }
  }

  if (nums[secondMaxIdx] + nums[secondMaxIdx] <= nums[maxIdx]) {
    return maxIdx;
  } else {
    return -1;
  }
}

int main()
{
  // 747. Largest Number At Least Twice of Others

  {
    std::vector<int> nums = {3, 6, 1, 0};
    assert(dominantIndex(nums) == 1);
  }

  {
    std::vector<int> nums = {1, 2, 3, 4};
    assert(dominantIndex(nums) == -1);
  }

  return 0;
}