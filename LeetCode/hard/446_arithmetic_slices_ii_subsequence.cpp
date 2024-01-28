#include <cassert>
#include <unordered_map>
#include <vector>

int numberOfArithmeticSlices(std::vector<int>& nums)
{
  std::unordered_map<long, std::vector<int>> container;
  for (int i = 0; i < nums.size(); ++i) {
    container[nums[i]].push_back(i);
  }

  int numSlices = 0;
  std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(nums.size(), 0));
  for (int i = 1; i < nums.size(); ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      long prev = 2l * nums[i] - nums[j];

      if (container.count(prev)) {
        for (int k: container[prev]) {
          if (k >= i) {
            break;
          }
          dp[i][j] += dp[k][i] + 1;
        }
      }

      numSlices += dp[i][j];
    }
  }

  return numSlices;
}

int main()
{
  // 446. Arithmetic Slices II - Subsequence

  {
    std::vector<int> nums = {2, 4, 6, 8, 10};
    assert(numberOfArithmeticSlices(nums) == 7);
  }

  {
    std::vector<int> nums = {7, 7, 7, 7, 7};
    assert(numberOfArithmeticSlices(nums) == 16);
  }

  return 0;
}
