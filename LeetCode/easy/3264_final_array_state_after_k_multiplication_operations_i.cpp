#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

std::vector<int> getFinalState(std::vector<int>& nums, int k, int multiplier)
{
  auto comp = [](const auto& lhs, const auto& rhs) -> bool {
    if (lhs.second == rhs.second) {
      return lhs.first > rhs.first;
    }
    return lhs.second > rhs.second;
  };

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> pq(comp);

  for (auto i = 0; i < nums.size(); ++i) {
    pq.push(std::make_pair(i, nums[i]));
  }

  while (k > 0) {
    auto [idx, value] = pq.top();
    pq.pop();
    pq.push(std::make_pair(idx, value * multiplier));
    --k;
  }

  std::vector<int> result(pq.size());
  while (!pq.empty()) {
    auto [idx, value] = pq.top();
    result[idx] = value;
    pq.pop();
  }

  return result;
}

int main()
{
  // 1792. Maximum Average Pass Ratio

  {
    std::vector<int> nums = {2, 1, 3, 5, 6};
    int k = 5;
    int multiplier = 2;
    getFinalState(nums, k, multiplier);
  }

  {
    std::vector<int> nums = {1, 3, 5};
    int k = 5;
    int multiplier = 3;
    getFinalState(nums, k, multiplier);
  }

  return 0;
}
