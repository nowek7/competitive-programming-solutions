#include <algorithm>
#include <cassert>
#include <vector>

int maximumBeauty(std::vector<int>& nums, int k)
{
  std::sort(nums.begin(), nums.end());

  int maxLength = 0;
  int left = 0;
  for (int right = 0; right < nums.size(); ++right) {
    while (nums[right] - nums[left] > 2 * k) {
      ++left;
    }

    maxLength = std::max(maxLength, right - left + 1);
  }

  return maxLength;
}

int main()
{
  // 2779. Maximum Beauty of an Array After Applying Operation

  {
    std::vector<int> nums = {4, 6, 1, 2};
    int k = 2;
    assert(maximumBeauty(nums, k) == 3);
  }

  {
    std::vector<int> nums = {1, 1, 1, 1};
    int k = 10;
    assert(maximumBeauty(nums, k) == 4);
  }

  return 0;
}
