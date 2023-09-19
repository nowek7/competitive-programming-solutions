#include <cassert>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

int findDuplicate(std::vector<int>& nums)
{
  std::unordered_map<int, int> frequency;
  for (auto elem: nums) {
    frequency[elem]++;
    if (frequency[elem] > 1) {
      return elem;
    }
  }
  return -1;
}

int findDuplicate_v2(std::vector<int>& nums)
{
  std::unordered_set<int> set;
  for (auto elem: nums) {
    if (set.count(elem) == 1) {
        return elem;
    } else {
        set.insert(elem);
    }
  }
  return -1;
}

int findDuplicate_v3(std::vector<int>& nums)
{
  int slow = nums[0];
  int fast = nums[nums[0]];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[nums[fast]];
  }
  fast = 0;
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }

  return slow;
}

int main()
{
  {
    std::vector<int> nums = {1, 3, 4, 3, 2};
    assert(findDuplicate(nums) == 3);
    assert(findDuplicate_v2(nums) == 3);
    assert(findDuplicate_v3(nums) == 3);
  }

  {
    std::vector<int> nums = {3, 1, 3, 4, 2};
    assert(findDuplicate(nums) == 3);
    assert(findDuplicate_v2(nums) == 3);
    assert(findDuplicate_v3(nums) == 3);
  }

  return 0;
}