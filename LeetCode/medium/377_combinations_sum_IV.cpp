#include <vector>

#include <iostream>

int combinationSum4(std::vector<int>& nums, int target)
{
    unsigned int results[target + 1];
    results[0] = 1;

    for (int i = 1; i <= target; ++i) {
        results[0] = 0;
        for (auto& number: nums) {
            if (i - number >= 0) {
                results[i] += results[i - number] % 1000000007;
            }
        }
    }
    return results[target];
}

int main()
{
  // 377. Combination Sum IV
  {
    std::vector<int> nums = { 1, 2, 3 };
    combinationSum4(nums, 9);
  }

  return 0;
}