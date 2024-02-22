#include <cassert>
#include <vector>

void moveZeroes(std::vector<int>& nums)
{
  int len = 0;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] != 0) {
      nums[len] = nums[i];
      ++len;
    }
  }

  for (int i = len; i < nums.size(); ++i) {
    nums[i] = 0;
  }
}

int main()
{
  // 283. Move Zeroes

  {
    std::vector<int> nums = {0, 1, 0, 3, 12};
    std::vector<int> expected = {1, 3, 12, 0, 0};
    moveZeroes(nums);
    assert(nums == expected);
  }

  {
    std::vector<int> nums = {0};
    std::vector<int> expected = {0};
    moveZeroes(nums);
    assert(nums == expected);
  }

  return 0;
}
