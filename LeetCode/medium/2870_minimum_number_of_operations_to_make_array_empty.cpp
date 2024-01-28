#include <cassert>
#include <unordered_map>
#include <vector>

int minOperations(std::vector<int>& nums)
{
  std::unordered_map<int, int> frequency;
  for (int num: nums) {
    ++frequency[num];
  }

  int numOps = 0;
  ;
  for (auto [k, v]: frequency) {
    if (v == 1) {
      return -1;
    }
    numOps += v / 3;
    if (v % 3 != 0) {
      ++numOps;
    }
  }
  return numOps;
}

int main()
{
  // 2870. Minimum Number of Operations to Make Array Empty

  {
    std::vector<int> nums = {2, 3, 3, 2, 2, 4, 2, 3, 4};
    assert(minOperations(nums) == 4);
  }

  {
    std::vector<int> nums = {2, 1, 2, 2, 3, 3};
    assert(minOperations(nums) == -1);
  }

  return 0;
}
