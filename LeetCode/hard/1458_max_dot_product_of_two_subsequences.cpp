#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

int maxDotProduct(std::vector<int>& nums1, std::vector<int>& nums2)
{
  std::vector<std::vector<int>> dp(nums1.size() + 1, std::vector<int>(nums2.size() + 1, INT_MIN));

  int currValue = 0;
  for (int i = 0; i < nums1.size() + 1; ++i) {
    for (int j = 0; j < nums2.size() + 1; ++j) {
      if (i > 0 && j > 0) {
        currValue = (nums1[i - 1] * nums2[j - 1]) + std::max(dp[i - 1][j - 1], 0);
        dp[i][j] = std::max(currValue, std::max(dp[i - 1][j], dp[i][j - 1]));
      }
    }
  }

  return dp.back().back();
}

int main()
{
  {
    std::vector<int> nums1 = {2, 1, -2, 5};
    std::vector<int> nums2 = {3, 0, -6};
    std::cout << maxDotProduct(nums1, nums2) << '\n';
  }

  {
    std::vector<int> nums1 = {3, -2};
    std::vector<int> nums2 = {2, -6, 7};
    std::cout << maxDotProduct(nums1, nums2) << '\n';
  }

  {
    std::vector<int> nums1 = {-1, -1};
    std::vector<int> nums2 = {1, 1};
    std::cout << maxDotProduct(nums1, nums2) << '\n';
  }

  return 0;
}
