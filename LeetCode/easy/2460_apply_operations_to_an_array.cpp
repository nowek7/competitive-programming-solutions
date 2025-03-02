#include <cassert>
#include <vector>

std::vector<int> applyOperations(std::vector<int>& nums)
{
  for (auto i = 0; i < nums.size() - 1; ++i) {
    if (nums[i] == nums[i + 1] && nums[i] != 0) {
      nums[i] *= 2;
      nums[i + 1] = 0;
    }
  }

  std::vector<int> result(nums.size(), 0);
  for (auto i = 0, j = 0; i < nums.size(); ++i) {
    if (nums[i] != 0) {
      result[j++] = nums[i];
    }
  }

  return result;
}

int main()
{
  // 2460. Apply Operations to an Array

  {
    std::vector<int> nums = {1, 2, 2, 1, 1, 0};
    std::vector<int> expected = {1, 4, 2, 0, 0, 0};
    assert(applyOperations(nums) == expected);
  }

  {
    std::vector<int> nums = {0, 1};
    std::vector<int> expected = {1, 0};
    assert(applyOperations(nums) == expected);
  }

  return 0;
}
