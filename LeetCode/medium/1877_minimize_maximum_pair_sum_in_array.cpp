#include <algorithm>
#include <cassert>
#include <climits>
#include <vector>

int minPairSum(std::vector<int>& nums)
{
  std::sort(nums.begin(), nums.end());

  int result = INT_MIN;
  for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
    int sumPair = nums[i] + nums[j];
    if (sumPair > result) {
      result = sumPair;
    }
  }

  return result;
}

int main()
{
  // 1877. Minimize Maximum Pair Sum in Array

  {
    std::vector<int> nums = {3, 5, 2, 3};
    assert(minPairSum(nums) == 7);
  }

  {
    std::vector<int> nums = {3, 5, 4, 2, 4, 6};
    assert(minPairSum(nums) == 8);
  }

  return 0;
}
