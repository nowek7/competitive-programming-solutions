#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

std::vector<int> sortArrayByParity(std::vector<int>& nums)
{
  std::sort(nums.begin(), nums.end(), [](auto lhs, auto rhs) {
    return (lhs & 1) < (rhs & 1);
  });

  return nums;
}

std::vector<int> sortArrayByParity_v2(std::vector<int>& nums)
{
  int oddIdx = -1;
  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] % 2 == 0) {
      if (oddIdx != -1) {
        std::swap(nums[i], nums[oddIdx]);
        while (oddIdx < i) {
          if (nums[++oddIdx] % 2 == 1) {
            break;
          }
        }
      }
    } else if (oddIdx == -1) {
      oddIdx = i;
    }
  }

  return nums;
}

std::vector<int> sortArrayByParity_v3(std::vector<int>& nums)
{
  std::vector<int> result(nums.size());
  int left = 0;
  int right = result.size() - 1;

  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] & 1) {
      result[right--] = nums[i];
    } else {
      result[left++] = nums[i];
    }
  }

  return result;
}

void printNums(const std::vector<int>& nums)
{
  if (!nums.empty()) {
    for (int i = 0; i < nums.size() - 1; ++i) {
      std::cout << nums[i] << " ";
    }
    std::cout << *nums.rbegin() << '\n';
  }
}

int main()
{
  // 905. Sort Array By Parity

  {
    std::vector<int> rawNums = {2, 1, 12, 15, 3, 4, 8, 11, 17};
    auto nums = sortArrayByParity_v2(rawNums);
    printNums(nums);
  }

  {
    std::vector<int> rawNums = {2, 1, 0};
    auto nums = sortArrayByParity_v2(rawNums);
    printNums(nums);
  }

  {
    std::vector<int> rawNums = {3363, 4833, 290,  3381, 4227, 1711, 1253, 2984, 2212, 874,  2358, 2049, 2846,
                                2543, 1557, 1786, 4189, 1254, 2803, 62,   3708, 1679, 228,  1404, 1200, 4766,
                                1761, 1439, 1796, 4735, 3169, 3106, 3578, 1940, 2072, 3254, 7,    961,  1672,
                                1197, 3187, 1893, 4377, 2841, 2072, 2011, 3509, 2091, 3311, 233};
    auto nums = sortArrayByParity_v3(rawNums);
    printNums(nums);
  }

  return 0;
}
