#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

long long findScore(std::vector<int>& nums)
{
  auto cmp = [](std::pair<int, int>& lhs, std::pair<int, int>& rhs) -> bool {
    if (lhs.first != rhs.first) {
      return lhs.first > rhs.first;
    }
    return lhs.second > rhs.second;
  };
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> numbersWithIndex(cmp);
  for (auto i = 0; i < nums.size(); ++i) {
    numbersWithIndex.push(std::make_pair(nums[i], i));
  }

  long long result = 0ll;
  while (!numbersWithIndex.empty()) {
    const auto [number, idx] = numbersWithIndex.top();
    numbersWithIndex.pop();

    if (nums[idx] != -1) {
      result += number;

      nums[idx] = -1;
      if (idx > 0) {
        nums[idx - 1] = -1;
      }
      if (idx < nums.size() - 1) {
        nums[idx + 1] = -1;
      }
    }
  }

  return result;
}

int main()
{
  // 2593. Find Score of an Array After Marking All Elements

  {
    std::vector<int> nums = {2, 1, 3, 4, 5, 2};
    assert(findScore(nums) == 7);
  }

  {
    std::vector<int> nums = {2, 3, 5, 1, 3, 2};
    assert(findScore(nums) == 5);
  }

  return 0;
}
