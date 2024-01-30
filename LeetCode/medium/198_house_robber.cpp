#include <cassert>
#include <stack>
#include <vector>

int rob(std::vector<int>& nums)
{
  std::vector<int> sums(nums.size() + 1, 0);
  sums[1] = nums[0];
  for (int i = 2; i <= nums.size(); ++i) {
    sums[i] = std::max(sums[i - 2] + nums[i - 1], sums[i - 1]);
  }

  return sums.back();
}

int main()
{
  // 198. House Robber

  {
    std::vector<int> nums = {1, 2, 3, 1};
    assert(rob(nums) == 4);
  }

  {
    std::vector<int> nums = {2, 7, 9, 3, 1};
    assert(rob(nums) == 12);
  }

  return 0;
}
