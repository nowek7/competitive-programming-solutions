#include <algorithm>
#include <cassert>
#include <ranges>
#include <unordered_map>
#include <vector>

long long countBadPairs(std::vector<int>& nums)
{
  long long numBadPairs = 0;
  std::unordered_map<int, int> counters;
  for (auto i = 0; i < nums.size(); ++i) {
    const int diff = i - nums[i];
    const int numGoodPairs = counters[diff];
    numBadPairs += i - numGoodPairs;
    counters[diff] = numGoodPairs + 1;
  }

  return numBadPairs;
}

long long countBadPairs_v2(std::vector<int>& nums)
{
  auto n = nums.size();
  long long num_bad_pairs = (n * (n - 1)) >> 1;
  for (auto [i, num]: nums | std::views::enumerate) {
    num -= i;
  }
  std::sort(begin(nums), end(nums));

  for (auto chunk: nums | std::views::chunk_by(std::equal_to {})) {
    auto m = std::size(chunk);
    num_bad_pairs -= (m * (m - 1)) >> 1;
  }
  return num_bad_pairs;
}

int main()
{
  // 2364. Count Number of Bad Pairs

  {
    std::vector<int> nums = {4, 1, 3, 3};
    assert(countBadPairs(nums) == 5);
    assert(countBadPairs_v2(nums) == 5);
  }

  {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    assert(countBadPairs(nums) == 0);
    assert(countBadPairs_v2(nums) == 0);
  }

  return 0;
}
