#include <cassert>
#include <queue>
#include <vector>

int minOperations(std::vector<int>& nums, int k)
{
  int result = 0;
  std::priority_queue<long, std::vector<long>, std::greater<>> line(nums.cbegin(), nums.cend());
  while (line.size() >= 2 && line.top() < k) {
    long min1 = line.top();
    line.pop();
    long min2 = line.top();
    line.pop();

    line.push(min1 * 2 + min2);
    ++result;
  }

  return result;
}

int main()
{
  // 3066. Minimum Operations to Exceed Threshold Value II

  {
    std::vector<int> nums = {2, 11, 10, 1, 3};
    int k = 10;
    assert(minOperations(nums, k) == 2);
  }

  {
    std::vector<int> nums = {1, 1, 2, 4, 9};
    int k = 20;
    assert(minOperations(nums, k) == 4);
  }

  return 0;
}
