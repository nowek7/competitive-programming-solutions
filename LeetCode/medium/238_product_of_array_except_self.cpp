#include <cassert>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums)
{
  int total = 1;
  int numZeros = 0;
  for (auto n: nums) {
    if (n != 0) {
      total *= n;
    } else {
      ++numZeros;
    }
  }

  std::vector<int> result(nums.size(), 0);
  for (auto i = 0; i < nums.size(); ++i) {
    if (numZeros == 0) {
      result[i] = total / nums[i];
    } else if (numZeros == 1) {
      if (nums[i] == 0) {
        result[i] = total;
      }
    }
  }

  return result;
}

int main()
{
  // 238. Product of Array Except Self

  {
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> expected = {24, 12, 8, 6};
    assert(productExceptSelf(nums) == expected);
  }

  {
    std::vector<int> nums = {-1, 1, 0, -3, 3};
    std::vector<int> expected = {0, 0, 9, 0, 0};
    assert(productExceptSelf(nums) == expected);
  }

  return 0;
}