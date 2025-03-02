#include <cassert>
#include <vector>

int maxScoreSightseeingPair(std::vector<int>& values)
{
  int maxResult = 0;
  int maxLeftResult = values[0];
  for (int i = 1; i < values.size(); ++i) {
    maxResult = std::max(maxResult, maxLeftResult + values[i] - i);
    maxLeftResult = std::max(maxLeftResult, values[i] + i);
  }

  return maxResult;
}

int main()
{
  // 1014. Best Sightseeing Pair

  {
    std::vector<int> nums = {8, 1, 5, 2, 6};
    assert(maxScoreSightseeingPair(nums) == 11);
  }

  {
    std::vector<int> nums = {1, 2};
    assert(maxScoreSightseeingPair(nums) == 2);
  }

  return 0;
}
