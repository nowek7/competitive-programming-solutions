#include <algorithm>
#include <iostream>
#include <vector>

void printNums(const std::vector<int>& nums)
{
  for (int i = 0; i < nums.size() - 1; ++i) {
    std::cout << nums[i] << " ";
  }
  std::cout << *nums.rbegin() << '\n';
}

int removeDuplicates(std::vector<int>& nums)
{
  int k = nums.size() - 1;
  for (int i = nums.size() - 1; i > 0; --i) {
    if (nums[i] == nums[i - 1]) {
      for (int j = i; j < k; ++j) {
        std::swap(nums[j], nums[j + 1]);
      }
      --k;
    }
  }

  return k + 1;
}

int removeDuplicates_2(std::vector<int>& nums)
{
  auto last = std::unique(nums.begin(), nums.end());
  nums.erase(last, nums.end());
  return nums.size();
}

int main()
{
  // 26. Remove Duplicates from Sorted Array
  {
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    int k = removeDuplicates(nums);
    std::cout << k << '\n';
  }

  {
    std::vector<int> nums = {1, 2, 3};
    int k = removeDuplicates(nums);
    std::cout << k << '\n';
  }

  {
    std::vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    int k = removeDuplicates(nums);
    std::cout << k << '\n';
  }

  {
    std::vector<int> nums = {-100, -99, 7, 8, 8, 10};
    int k = removeDuplicates(nums);
    std::cout << k << '\n';
  }

  {
    std::vector<int> nums = {1, 1, 2};
    int k = removeDuplicates(nums);
    std::cout << k << '\n';
  }

  {
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k = removeDuplicates(nums);
    std::cout << k << '\n';
  }

  return 0;
}