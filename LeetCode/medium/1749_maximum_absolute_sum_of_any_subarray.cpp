#include <cassert>
#include <vector>

int maxAbsoluteSum(std::vector<int>& nums)
{
  int minPrefixSum = 0;
  int maxPrefixSum = 0;

  int prefixSum = 0;
  for (int i = 0; i < nums.size(); i++) {
    prefixSum += nums[i];

    minPrefixSum = std::min(minPrefixSum, prefixSum);
    maxPrefixSum = std::max(maxPrefixSum, prefixSum);
  }

  return maxPrefixSum - minPrefixSum;
}

int main()
{
  // 1749. Maximum Absolute Sum of Any Subarray

  {
    std::vector<int> nums = {1, -3, 2, 3, -4};
    assert(maxAbsoluteSum(nums) == 5);
  }

  {
    std::vector<int> nums = {2, -5, 1, -4, 3, -2};
    assert(maxAbsoluteSum(nums) == 8);
  }

  return 0;
}
