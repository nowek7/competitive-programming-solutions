#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
  int left = nums1.size() - 1;
  while (m > 0 && n > 0) {
    if (nums1[m - 1] > nums2[n - 1]) {
      nums1[left] = nums1[m - 1];
      --m;
    } else {
      nums1[left] = nums2[n - 1];
      --n;
    }
    --left;
  }

  while (m > 0) {
    nums1[left--] = nums1[m - 1];
    --m;
  }
  while (n > 0) {
    nums1[left--] = nums2[n - 1];
    --n;
  }
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
  // 88. Merge Sorted Array
  {
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    merge(nums1, 3, nums2, 3);
    printNums(nums1);
  }

  {
    std::vector<int> nums1 = {1};
    std::vector<int> nums2 = {};
    merge(nums1, 1, nums2, 0);
    printNums(nums1);
  }

  {
    std::vector<int> nums1 = {0};
    std::vector<int> nums2 = {1};
    merge(nums1, 0, nums2, 1);
    printNums(nums1);
  }

  {
    std::vector<int> nums1 = {2, 4, 6, 8, 10, 0, 0, 0};
    std::vector<int> nums2 = {1, 3, 5};
    merge(nums1, 5, nums2, 3);
    printNums(nums1);
  }

  {
    std::vector<int> nums1 = {2, 4, 6, 8, 10, 0, 0, 0, 0, 0, 0};
    std::vector<int> nums2 = {1, 2, 3, 4, 5, 6};
    merge(nums1, 5, nums2, 6);
    printNums(nums1);
  }

  {
    std::vector<int> nums1 = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    std::vector<int> nums2 = {1, 1, 1, 1, 1, 1};
    merge(nums1, 5, nums2, 6);
    printNums(nums1);
  }

  {
    std::vector<int> nums1 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<int> nums2 = {1, 1, 1, 1, 1, 1};
    merge(nums1, 5, nums2, 6);
    printNums(nums1);
  }

  return 0;
}
