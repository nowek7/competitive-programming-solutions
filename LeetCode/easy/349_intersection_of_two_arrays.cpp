#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::vector<int> intersection(std::vector<int> nums1, std::vector<int> nums2)
{
  std::unordered_set<int> set1(nums1.begin(), nums1.end());
  std::unordered_set<int> set2(nums2.begin(), nums2.end());

  std::vector<int> result;
  for (int num: set1) {
    if (set2.count(num) > 0) {
      result.push_back(num);
    }
  }

  return result;
}

std::vector<int> intersection(std::vector<int> nums1, std::vector<int> nums2)
{
  std::unordered_map<int, bool> mapNums;
  for (auto elem: nums1) {
    mapNums[elem] = true;
  }

  std::vector<int> result;
  for (auto num: nums2) {
    if (mapNums[num]) {
      result.push_back(num);
      mapNums[num] = false;
    }
  }

  return result;
}

void print(std::vector<int>& sequence)
{
  if (!sequence.empty()) {
    for (int i = 0; i < sequence.size() - 1; ++i) {
      std::cout << sequence.at(i) << " ";
    }
    std::cout << *sequence.rbegin() << '\n';
  }
}

int main()
{
  // 349. Intersection of Two Arrays
  {
    std::vector<int> nums1 = {};
    std::vector<int> nums2 = {};
    auto result = intersection(nums1, nums2);
    print(result);
  }
}