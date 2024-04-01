#include <cassert>
#include <unordered_map>
#include <vector>

int subarraysWithKDistinct(std::vector<int>& nums, int k)
{
  auto helper = [&nums](int k) {
    std::unordered_map<int, int> elements;
    int counter = 0;
    int left = 0;

    for (std::size_t right = 0; right < nums.size(); ++right) {
      ++elements[nums[right]];
      while (static_cast<int>(elements.size()) > k) {
        --elements[nums[left]];
        if (elements[nums[left]] == 0) {
          elements.erase(nums[left]);
        }
        ++left;
      }

      counter += right - left + 1;
    }

    return counter;
  };

  return helper(k) - helper(k - 1);
}

int main()
{
  // 992. Subarrays with K Different Integers

  {
    std::vector<int> nums = {1, 2, 1, 2, 3};
    assert(subarraysWithKDistinct(nums, 2) == 7);
  }

  {
    std::vector<int> nums = {1, 2, 1, 3, 4};
    assert(subarraysWithKDistinct(nums, 3) == 3);
  }

  return 0;
}
