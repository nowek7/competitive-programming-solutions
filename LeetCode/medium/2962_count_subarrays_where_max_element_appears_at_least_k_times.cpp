#include <algorithm>
#include <cassert>
#include <vector>

long long countSubarrays(std::vector<int>& nums, int k)
{
  const int maxElement = *std::max_element(nums.cbegin(), nums.cend());
  int frequency = 0;

  long long count = 0;
  int left = 0;
  for (std::size_t right = 0; right < nums.size(); ++right) {
    if (maxElement == nums[right]) {
      ++frequency;
    }

    while (frequency == k) {
      if (nums[left] == maxElement) {
        --frequency;
      }
      ++left;
    }
    count += left;
  }

  return count;
}

int main()
{
  // 2962. Count Subarrays Where Max Element Appears at Least K Times

  {
    std::vector<int> nums = {1, 3, 2, 3, 3};
    assert(countSubarrays(nums, 2) == 6);
  }

  {
    std::vector<int> nums = {1, 4, 2, 1};
    assert(countSubarrays(nums, 3) == 3);
  }

  return 0;
}
