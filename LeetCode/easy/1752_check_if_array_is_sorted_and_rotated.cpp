#include <algorithm>
#include <cassert>
#include <vector>

bool check(std::vector<int>& nums)
{
  std::vector<int> originalNums = nums;
  std::sort(originalNums.begin(), originalNums.end());

  const int count = nums.size();
  for (auto shift = 0; shift < count; ++shift) {
    bool isValid = true;
    for (auto i = 0; i < count; ++i) {
      const auto idx = (shift + i) % count;
      if (originalNums[idx] != nums[i]) {
        isValid = false;
        break;
      }
    }

    if (isValid) {
      return true;
    }
  }

  return false;
}

int main()
{
  // 1752. Check if Array Is Sorted and Rotated

  {
    std::vector<int> nums = {3, 4, 5, 1, 2};
    assert(check(nums) == true);
  }

  {
    std::vector<int> nums = {2, 1, 3, 4};
    assert(check(nums) == false);
  }

  {
    std::vector<int> nums = {1, 2, 3};
    assert(check(nums) == true);
  }

  return 0;
}
