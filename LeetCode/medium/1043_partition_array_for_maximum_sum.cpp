#include <cassert>
#include <vector>

int maxSumAfterPartitioning(std::vector<int>& arr, int k)
{
  std::vector<int> dp(arr.size() + 1, 0);
  for (int i = 0; i < arr.size(); ++i) {
    int currMax = 0;
    int currSum = 0;

    for (int j = i; j >= std::max(0, i - k + 1); --j) {
      currMax = std::max(currMax, arr[j]);
      currSum = std::max(currSum, currMax * (i - j + 1) + dp[j]);
    }

    dp[i + 1] = currSum;
  }

  return dp.back();
}

int main()
{
  // 1043. Partition Array for Maximum Sum

  {
    std::vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    assert(maxSumAfterPartitioning(arr, 3) == 84);
  }

  {
    std::vector<int> arr = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
    assert(maxSumAfterPartitioning(arr, 4) == 83);
  }

  {
    std::vector<int> arr = {1};
    assert(maxSumAfterPartitioning(arr, 1) == 1);
  }

  return 0;
}
