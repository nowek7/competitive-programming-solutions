#include <cassert>
#include <vector>

std::vector<int> rearrangeArray(std::vector<int>& nums)
{
  std::vector<int> result(nums.size());

  int positiveIdx = 0;
  int negativeIdx = 1;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] > 0) {
      result[positiveIdx] = nums[i];
      positiveIdx += 2;
    } else {
      result[negativeIdx] = nums[i];
      negativeIdx += 2;
    }
  }

  return result;
}

int main()
{
  // 2149. Rearrange Array Elements by Sign

  {
    std::vector<int> nums = {3, 1, -2, -5, 2, -4};
    std::vector<int> expected = {3, -2, 1, -5, 2, -4};
    assert(rearrangeArray(nums) == expected);
  }

  {
    std::vector<int> nums = {-1, 1};
    std::vector<int> expected = {1, -1};
    assert(rearrangeArray(nums) == expected);
  }

  return 0;
}
