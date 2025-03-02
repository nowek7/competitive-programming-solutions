#include <cassert>
#include <vector>

std::vector<std::vector<int>> mergeArrays(std::vector<std::vector<int>>& nums1, std::vector<std::vector<int>>& nums2)
{
  std::vector<std::vector<int>> result;
  result.reserve(nums1.size() + nums2.size());

  const int maxId = std::max(nums1[nums1.size() - 1][0], nums2[nums2.size() - 1][0]);
  int i = 0;
  int j = 0;
  for (auto id = 1; id <= maxId; ++id) {
    if (i < nums1.size() && j < nums2.size() && id == nums1[i][0] && id == nums2[j][0]) {
      result.push_back({id, nums1[i][1] + nums2[j][1]});
      ++i;
      ++j;
    } else if (i < nums1.size() && id == nums1[i][0]) {
      result.push_back(nums1[i]);
      ++i;
    } else if (j < nums2.size() && id == nums2[j][0]) {
      result.push_back(nums2[j]);
      ++j;
    }
  }

  return result;
}

int main()
{
  // 2570. Merge Two 2D Arrays by Summing Values

  {
    std::vector<std::vector<int>> nums1 = {
      {1, 2},
      {2, 3},
      {4, 5}
    };
    std::vector<std::vector<int>> nums2 = {
      {1, 4},
      {3, 2},
      {4, 1}
    };
    std::vector<std::vector<int>> expected = {
      {1, 6},
      {2, 3},
      {3, 2},
      {4, 6}
    };
    auto result = mergeArrays(nums1, nums2);
    assert(result == expected);
  }

  // {
  //     std::vector<std::vector<int>> nums1 = {{2,4},{3,6},{5,5}};
  //     std::vector<std::vector<int>> nums2 = {{1,3},{4,3}};
  //     std::vector<std::vector<int>> expected = {
  //         {1,3},{2,4},{3,6},{4,3},{5,5}
  //     };
  //     auto result = mergeArrays(nums1, nums2);
  //     assert(result == expected);
  // }

  return 0;
}
