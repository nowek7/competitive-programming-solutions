#include <cassert>
#include <cmath>
#include <vector>

long long countSubarrays(std::vector<int>& nums, int minK, int maxK)
{
  long long result = 0;

  int left = -1;
  int right = -1;
  int outsideIdx = -1;
  for (std::size_t i = 0; i < nums.size(); ++i) {
    if (!(minK <= nums[i] && nums[i] <= maxK)) {
      outsideIdx = i;
    }

    if (nums[i] == minK) {
      left = i;
    }

    if (nums[i] == maxK) {
      right = i;
    }

    result += std::max(0, std::min(left, right) - outsideIdx);
  }

  return result;
}

int main()
{
  // 2444. Count Subarrays With Fixed Bounds

  {
    std::vector<int> nums = {1, 3, 5, 2, 7, 5};
    int minK = 1;
    int maxK = 5;
    assert(countSubarrays(nums, minK, maxK) == 2);
  }

  {
    std::vector<int> nums = {1, 1, 1, 1};
    int minK = 1;
    int maxK = 1;
    assert(countSubarrays(nums, minK, maxK) == 10);
  }

  return 0;
}
