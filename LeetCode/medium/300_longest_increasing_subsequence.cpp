#include <cassert>
#include <vector>

int lengthOfLIS(std::vector<int>& nums)
{
  std::vector<int> dp(nums.size(), 0);
  int len = 0;
  for (int num: nums) {
    int left = 0;
    int right = len;
    while (left != right) {
      int mid = (left + right) * 0.5;
      if (dp[mid] < num) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    dp[left] = num;
    if (left == len) {
      ++len;
    }
  }

  return len;
}

int main()
{
  // 300. Longest Increasing Subsequence

  {
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    assert(lengthOfLIS(nums) == 4);
  }

  {
    std::vector<int> nums = {0, 1, 0, 3, 2, 3};
    assert(lengthOfLIS(nums) == 4);
  }

  {
    std::vector<int> nums = {7, 7, 7, 7, 7, 7, 7};
    assert(lengthOfLIS(nums) == 1);
  }

  return 0;
}
