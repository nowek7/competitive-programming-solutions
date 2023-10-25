#include <cassert>
#include <vector>

int firstMissingPositive(std::vector<int>& nums)
{
  for (int i = 0; i < nums.size(); ++i) {
    while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
      std::swap(nums[i], nums[nums[i] - 1]);
    }
  }

  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] != i + 1) {
      return i + 1;
    }
  }

  return nums.size() + 1;
}

int main()
{
  // 41. First Missing Positive

  {
    std::vector<int> nums = {1, 2, 0};
    assert(firstMissingPositive(nums) == 3);
  }

  {
    std::vector<int> nums = {3, 4, -1, 1};
    assert(firstMissingPositive(nums) == 2);
  }

  {
    std::vector<int> nums = {7, 8, 9, 11, 12};
    assert(firstMissingPositive(nums) == 1);
  }

  return 0;
}