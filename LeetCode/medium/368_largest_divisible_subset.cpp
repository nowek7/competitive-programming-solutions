#include <algorithm>
#include <cassert>
#include <vector>

std::vector<int> largestDivisibleSubset(std::vector<int>& nums)
{
  if (nums.size() == 1) {
    return nums;
  }

  std::sort(nums.begin(), nums.end());

  std::vector<int> dp(nums.size(), 1);
  std::vector<int> indicies(nums.size(), -1);
  int maxIdx = 0;
  for (int i = 1; i < nums.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
        indicies[i] = j;
        if (dp[i] > dp[maxIdx]) {
          maxIdx = i;
        }
      }
    }
  }

  std::vector<int> result;
  while (maxIdx >= 0) {
    result.push_back(nums[maxIdx]);
    maxIdx = indicies[maxIdx];
  }

  return result;
}

int main()
{
  // 368. Largest Divisible Subset

  {
    std::vector<int> nums = {1, 2, 4, 8};
    std::vector<int> expected = {1, 2, 4, 8};
    std::vector<int> result = largestDivisibleSubset(nums);
    std::reverse(result.begin(), result.end());
    assert(result == expected);
  }

  return 0;
}
