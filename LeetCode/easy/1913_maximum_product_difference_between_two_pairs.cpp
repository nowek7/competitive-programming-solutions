#include <cassert>
#include <vector>

int maxProductDifference(std::vector<int>& nums)
{
  std::pair<int, int> maxPair {nums[0], nums[1]};
  std::pair<int, int> minPair {nums[0], nums[1]};
  for (int i = 2; i < nums.size(); ++i) {
    if (nums[i] >= maxPair.first) {
      maxPair.second = std::max(maxPair.first, maxPair.second);
      maxPair.first = nums[i];
    } else if (nums[i] >= maxPair.second) {
      maxPair.second = nums[i];
    }

    if (nums[i] <= minPair.first) {
      minPair.second = std::min(minPair.first, minPair.second);
      minPair.first = nums[i];
    } else if (nums[i] <= minPair.second) {
      minPair.second = nums[i];
    }
  }

  return (maxPair.first * maxPair.second) - (minPair.first * minPair.second);
}

int maxProductDifference_v2(vector<int>& nums)
{
  const int n = nums.size();
  std::sort(nums.begin(), nums.end());
  return (nums[n - 1] * nums[n - 2]) - (nums[0] * nums[1]);
}

int main()
{
  // 1913. Maximum Product Difference Between Two Pairs

  {
    std::vector<int> nums = {5, 6, 2, 7, 4};
    assert(maxProductDifference(nums) == 34);
  }

  {
    std::vector<int> nums = {4, 2, 5, 9, 7, 4, 8};
    assert(maxProductDifference(nums) == 64);
  }

  return 0;
}
