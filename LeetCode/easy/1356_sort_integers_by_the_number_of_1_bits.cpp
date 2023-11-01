#include <algorithm>
#include <bit>
#include <iostream>
#include <vector>

std::vector<int> sortByBits(std::vector<int>& arr)
{
  std::sort(arr.begin(), arr.end(), [](auto lhs, auto rhs) {
    const int lcount = __builtin_popcount(lhs);
    const int rcount = __builtin_popcount(rhs);
    if (lcount == rcount) {
      return lhs < rhs;
    } else {
      return lcount < rcount;
    }
  });

  return arr;
}

void printNums(const std::vector<int>& nums)
{
  if (!nums.empty()) {
    for (int i = 0; i < nums.size() - 1; ++i) {
      std::cout << nums[i] << " ";
    }
    std::cout << nums.back() << '\n';
  }
}

int main()
{
  // 1356. Sort Integers by The Number of 1 Bits
  {
    std::vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    nums = sortByBits(nums);
    printNums(nums);
  }

  {
    std::vector<int> nums = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    nums = sortByBits(nums);
    printNums(nums);
  }

  return 0;
}