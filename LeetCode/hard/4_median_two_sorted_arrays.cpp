#include <vector>
#include <algorithm>

#include <iostream>

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
    //  return 0.f;
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