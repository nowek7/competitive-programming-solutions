#include <cassert>
#include <vector>

bool isArraySpecial(std::vector<int>& nums)
{
  for (int i = 0; i < nums.size() - 1; ++i) {
    if (nums[i] % 2 == nums[i + 1] % 2) {
      return false;
    }
  }

  return true;
}

int main()
{
  // 3151. Special Array I

  {
    std::vector<int> nums = {1};
    assert(isArraySpecial(nums) == true);
  }

  {
    std::vector<int> nums = {2, 1, 4};
    assert(isArraySpecial(nums) == true);
  }

  {
    std::vector<int> nums = {4, 3, 1, 6};
    assert(isArraySpecial(nums) == false);
  }

  return 0;
}
