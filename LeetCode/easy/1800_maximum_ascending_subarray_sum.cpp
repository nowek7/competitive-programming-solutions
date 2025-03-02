#include <cassert>
#include <vector>

int maxAscendingSum(const std::vector<int>& nums)
{
  if (nums.empty()) {
    return 0;
  }

  int maxSum = nums[0];
  int currentSum = nums[0];
  for (auto i = 1; i < nums.size(); ++i) {
    if (nums[i] > nums[i - 1]) {
      currentSum += nums[i];
    } else {
      maxSum = std::max(maxSum, currentSum);
      currentSum = nums[i];
    }

    maxSum = std::max(maxSum, currentSum);
  }

  return maxSum;
}

int main()
{
  // 1800. Maximum Ascending Subarray Sum

  {
    // Test case 1: Ascending sequence
    std::vector<int> nums1 = {10, 20, 30, 40, 50};
    assert(maxAscendingSum(nums1) == 150);
  }

  {
    // Test case 2: Decreasing sequence
    std::vector<int> nums2 = {50, 40, 30, 20, 10};
    assert(maxAscendingSum(nums2) == 50);
  }

  {
    // Test case 3: Mixed sequence
    std::vector<int> nums3 = {10, 20, 15, 5, 90, 100};
    assert(maxAscendingSum(nums3) == 195);
  }

  {
    // Test case 4: Empty vector
    std::vector<int> nums4 = {};
    assert(maxAscendingSum(nums4) == 0);
  }

  {
    // Test case 5: Single element vector
    std::vector<int> nums5 = {5};
    assert(maxAscendingSum(nums5) == 5);
  }

  {
    // Test case 6: Partially ascending sequence at the end.
    std::vector<int> nums6 = {12, 17, 15, 13, 10, 11, 12};
    assert(maxAscendingSum(nums6) == 33);
  }

  return 0;
}
