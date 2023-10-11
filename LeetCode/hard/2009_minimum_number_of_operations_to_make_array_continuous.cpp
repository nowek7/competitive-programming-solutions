#include <algorithm>
#include <iostream>
#include <vector>

int minOperations(std::vector<int>& nums)
{
  const int baseSize = nums.size();
  int minOperations = nums.size() - 1;
  std::sort(nums.begin(), nums.end());
  auto pos = std::unique(nums.begin(), nums.end());
  nums.erase(pos, nums.end());

  for (int i = 0, j = 0; i < nums.size(); ++i) {
    while (j < nums.size() && nums[j] < nums[i] + baseSize) {
      ++j;
    }
    minOperations = std::min(minOperations, baseSize - j + i);
  }

  return minOperations;
}

int main()
{
  // 2009. Minimum Number of Operations to Make Array Continuous
  {
    std::vector<int> nums = {4, 2, 5, 3};
    std::cout << "Number of min operations -> " << minOperations(nums) << '\n';
  }

  {
    std::vector<int> nums = {1, 10, 100, 1000};
    std::cout << "Number of min operations -> " << minOperations(nums) << '\n';
  }

  return 0;
}