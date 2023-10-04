#include <algorithm>
#include <iostream>
#include <vector>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
  std::vector<int> dst;
  dst.reserve(nums1.size() + nums2.size());
  std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(dst));

  const int idx = dst.size() * 0.5;
  if (dst.size() % 2 == 0) {
    return 0.5 * (dst[idx] + dst[idx - 1]);
  } else {
    return dst[idx];
  }
}

double findMedianSortedArrays_v2(std::vector<int>& nums1, std::vector<int>& nums2)
{
  std::vector<int> result(nums1.size() + nums2.size());
  int lhs = 0;
  int rhs = 0;
  for (int i = 0; i < result.size(); ++i) {
    if (lhs < nums1.size() && rhs < nums2.size()) {
      result[i] = nums1[lhs] < nums2[rhs] ? nums1[lhs++] : nums2[rhs++];
    } else {
      if (lhs < nums1.size()) {
        result[i] = nums1[lhs++];
      }
      if (rhs < nums2.size()) {
        result[i] = nums2[rhs++];
      }
    }
  }

  const int idx = result.size() * 0.5;
  if (result.size() % 2 == 0) {
    return 0.5 * (result[idx] + result[idx - 1]);
  } else {
    return result[idx];
  }
}

double findMedianSortedArrays_v3(std::vector<int>& nums1, std::vector<int>& nums2)
{
  int lhs = 0;
  int rhs = 0;
  std::pair<int, int> median = {0, 0};
  while ((lhs + rhs) <= (nums1.size() + nums2.size()) * 0.5) {
    if (lhs < nums1.size() && rhs < nums2.size()) {
      if (nums1[lhs] < nums2[rhs]) {
        median = {median.second, nums1[lhs++]};
      } else {
        median = {median.second, nums2[rhs++]};
      }
    } else {
      if (lhs < nums1.size()) {
        median = {median.second, nums1[lhs++]};
      }
      if (rhs < nums2.size()) {
        median = {median.second, nums2[rhs++]};
      }
    }
  }

  if ((nums1.size() + nums2.size()) % 2 == 0) {
    return 0.5 * (median.first + median.second);
  } else {
    return median.second;
  }
}

int main()
{
  // 4. Median of Two Sorted Arrays
  {
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    std::cout << findMedianSortedArrays(nums1, nums2) << '\n';
  }

  {
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {3, 4};
    std::cout << findMedianSortedArrays(nums1, nums2) << '\n';
  }

  {
    std::vector<int> nums1 = {2, 7, 11, 15};
    std::vector<int> nums2 = {2, 7, 11, 15};
    std::cout << findMedianSortedArrays(nums1, nums2) << '\n';
  }

  return 0;
}
