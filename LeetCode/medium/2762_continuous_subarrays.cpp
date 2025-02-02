#include <cassert>
#include <map>
#include <queue>
#include <vector>

long long continuousSubarrays(std::vector<int>& nums)
{
  long long result = 0ll;

  std::map<int, int> freq;
  std::size_t left = 0;
  for (auto right = 0; right < nums.size(); ++right) {
    ++freq[nums[right]];
    while (freq.rbegin()->first - freq.begin()->first > 2) {
      --freq[nums[left]];
      if (freq[nums[left]] == 0) {
        freq.erase(nums[left]);
      }

      ++left;
    }

    result += right - left + 1;
  }

  return result;
}

int main()
{
  // 2762. Continuous Subarrays

  {
    std::vector<int> nums = {5, 4, 2, 4};
    assert(continuousSubarrays(nums) == 8);
  }

  {
    std::vector<int> nums = {1, 2, 3};
    assert(continuousSubarrays(nums) == 6);
  }

  {
    std::vector<int> nums = {1, 4, 2, 1, 3};
    assert(continuousSubarrays(nums) == 9);
  }

  {
    std::vector<int> nums = {65, 66, 67, 66, 66, 65, 64, 65, 65, 64};
    assert(continuousSubarrays(nums) == 43);
  }

  {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(continuousSubarrays(nums) == 27);
  }

  return 0;
}
