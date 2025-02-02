#include <array>
#include <iostream>
#include <vector>

inline bool bothAreDifferentParity(int lhs, int rhs)
{
  if ((lhs % 2 == 1) && (rhs % 2 == 1)) {
    return false;
  }

  if ((lhs % 2 == 0) && (rhs % 2 == 0)) {
    return false;
  }

  return true;
}

inline bool search(const std::vector<std::array<int, 2>>& subarrays, const std::vector<int>& query)
{
  int left = 0;
  int right = subarrays.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    const auto& array = subarrays[mid];
    if (query[0] >= array[0] && query[1] <= array[1]) {
      return true;
    } else if (query[0] > array[1]) {
      left = mid + 1;
    } else if (query[1] < array[0]) {
      right = mid - 1;
    } else {
      return false;
    }
  }

  return false;
}

std::vector<bool> isArraySpecial(std::vector<int>& nums, std::vector<std::vector<int>>& queries)
{
  std::vector<std::array<int, 2>> subarrays;
  {
    int idx = 0;
    for (auto i = 1; i < nums.size(); ++i) {
      if (!bothAreDifferentParity(nums[i - 1], nums[i])) {
        subarrays.push_back({idx, i - 1});
        idx = i;
      }
    }
    subarrays.push_back({idx, static_cast<int>(nums.size() - 1)});
  }

  std::vector<bool> result;
  for (auto query: queries) {
    result.emplace_back(search(subarrays, query));
  }

  return result;
}

std::vector<bool> isArraySpecial_v2(std::vector<int>& nums, std::vector<std::vector<int>>& queries)
{
  std::vector<int> prefixSums(nums.size(), 0);
  prefixSums[0] = 1;
  for (auto i = 1; i < nums.size(); ++i) {
    if ((nums[i - 1] & 1) == (nums[i] & 1)) {
      prefixSums[i] = 1;
    } else {
      prefixSums[i] = prefixSums[i - 1] + 1;
    }
  }

  std::vector<bool> result;
  for (auto query: queries) {
    const int& left = query[0];
    const int& right = query[1];
    const int length = right - left;
    if (prefixSums[right] >= length) {
      result.push_back(true);
    } else {
      result.push_back(false);
    }
  }

  return result;
}

void printResults(const std::vector<bool>& results)
{
  for (auto i = 0; i < results.size() - 1; ++i) {
    std::cout << std::boolalpha << results[i] << ' ';
  }
  std::cout << std::boolalpha << results.back() << '\n';
}

int main()
{
  // 3152. Special Array II

  {
    std::vector<int> nums = {3, 4, 1, 2, 6};
    std::vector<std::vector<int>> queries = {
      {0, 4}
    };
    const auto results = isArraySpecial(nums, queries);
    printResults(results);
  }

  {
    std::vector<int> nums = {4, 3, 1, 6};
    std::vector<std::vector<int>> queries = {
      {0, 2},
      {2, 3}
    };
    const auto results = isArraySpecial_v2(nums, queries);
    printResults(results);
  }

  return 0;
}