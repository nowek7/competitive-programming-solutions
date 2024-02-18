#include <algorithm>
#include <cassert>
#include <vector>

std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k)
{
  std::sort(nums.begin(), nums.end());

  std::vector<std::vector<int>> result;
#pragma unroll
  for (int i = 0; i <= nums.size() - 3; i += 3) {
    if (nums[i + 2] - nums[i] <= k) {
      result.push_back({nums[i], nums[i + 1], nums[i + 2]});
    } else {
      return {};
    }
  }

  return result;
}

int main()
{
  // 2966. Divide Array Into Arrays With Max Difference

  {
    std::vector<int> nums = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k = 2;
    std::vector<std::vector<int>> expected = {
      {1, 1, 3},
      {3, 4, 5},
      {7, 8, 9}
    };
    std::vector<std::vector<int>> result = divideArray(nums, k);
    assert(expected == result);
  }

  {
    std::vector<int> nums = {1, 3, 3, 2, 7, 3};
    int k = 3;
    std::vector<std::vector<int>> expected;
    std::vector<std::vector<int>> result = divideArray(nums, k);
    assert(expected == result);
  }

  return 0;
}
