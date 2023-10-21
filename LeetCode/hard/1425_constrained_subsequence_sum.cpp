#include <algorithm>
#include <cassert>
#include <deque>
#include <vector>

int constrainedSubsetSum(std::vector<int>& nums, int k)
{
  std::vector<int> dp(nums);
  std::deque<int> doubleLine;
  doubleLine.push_back(0);

  for (int i = 1; i < nums.size(); ++i) {
    while (!doubleLine.empty() && doubleLine.back() < i - k) {
      doubleLine.pop_back();
    }
    dp[i] = std::max(dp[i], dp[doubleLine.back()] + nums[i]);
    while (!doubleLine.empty() && dp[doubleLine.front()] <= dp[i]) {
      doubleLine.pop_front();
    }
    doubleLine.push_front(i);
  }

  return *std::max_element(dp.begin(), dp.end());
}

int main()
{
  // 1425. Constrained Subsequence Sum

  {
    std::vector<int> nums = {10, 2, -10, 5, 20};
    assert(constrainedSubsetSum(nums, 2) == 37);
  }

  {
    std::vector<int> nums = {-1, -2, -3};
    assert(constrainedSubsetSum(nums, 1) == -1);
  }

  {
    std::vector<int> nums = {10, -2, -10, -5, 20};
    assert(constrainedSubsetSum(nums, 2) == 23);
  }

  return 0;
}
