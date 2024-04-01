#include <cassert>
#include <vector>

int numSubarrayProductLessThanK(std::vector<int>& nums, int k)
{
  if (k <= 1) {
    return 0;
  }

  int prod = 1;
  int count = 0;
  for (std::size_t left = 0, right = 0; right < nums.size();) {
    prod *= nums[right];
    while (prod >= k) {
      prod /= nums[left];
      ++left;
    }
    count += 1 + (right - left);
    ++right;
  }

  return count;
}

int main()
{
  // 713. Subarray Product Less Than K

  {
    std::vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    assert(numSubarrayProductLessThanK(nums, k) == 8);
  }

  {
    std::vector<int> nums = {1, 2, 3};
    int k = 0;
    assert(numSubarrayProductLessThanK(nums, k) == 0);
  }

  return 0;
}
