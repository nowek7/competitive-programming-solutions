#include <cassert>
#include <unordered_map>
#include <vector>

int findMaxLength(std::vector<int>& nums)
{
  std::unordered_map<int, int> store = {
    {0, -1}
  };
  int pref = 0;

  int maxLength = 0;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] == 0) {
      --pref;
    } else {
      ++pref;
    }

    if (store.find(pref) != store.end()) {
      maxLength = std::max(maxLength, i - store[pref]);
    } else {
      store[pref] = i;
    }
  }

  return maxLength;
}

int main()
{
  // 525. Contiguous Array

  {
    std::vector<int> nums = {0, 1};
    assert(findMaxLength(nums) == 2);
  }

  {
    std::vector<int> nums = {0, 1, 0};
    assert(findMaxLength(nums) == 2);
  }

  {
    std::vector<int> nums = {0, 1, 1, 1, 1, 1};
    assert(findMaxLength(nums) == 2);
  }

  {
    std::vector<int> nums = {0, 1, 0, 0, 0};
    assert(findMaxLength(nums) == 2);
  }

  {
    std::vector<int> nums = {0, 1, 0, 1, 0};
    assert(findMaxLength(nums) == 4);
  }

  {
    std::vector<int> nums = {0, 1, 0, 1, 0, 1};
    assert(findMaxLength(nums) == 5);
  }

  return 0;
}