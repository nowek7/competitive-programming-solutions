#include <cassert>
#include <vector>

int waysToSplitArray(std::vector<int>& nums)
{
  std::vector<long long> prefSum(nums.size(), 0);
  prefSum[0] = nums[0];

  for (auto i = 1; i < nums.size(); ++i) {
    prefSum[i] = prefSum[i - 1] + nums[i];
  }

  int result = 0;
  for (int i = 0, j = nums.size() - 1; i < nums.size() - 1; i++, j > 0) {
    if (prefSum[i] >= prefSum[j] - prefSum[i]) {
      ++result;
    }
  }

  return result;
}

int main()
{
  // 2270. Number of Ways to Split Array

  {
    std::vector<int> nums = {10, 4, -8, 7};
    assert(waysToSplitArray(nums) == 2);
  }

  {
    std::vector<int> nums = {2, 3, 1, 0};
    assert(waysToSplitArray(nums) == 2);
  }

  return 0;
}
