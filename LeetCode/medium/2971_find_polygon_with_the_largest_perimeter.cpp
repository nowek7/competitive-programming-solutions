#include <algorithm>
#include <cassert>
#include <vector>

long long largestPerimeter(std::vector<int>& nums)
{
  std::sort(nums.begin(), nums.end());

  std::vector<long long> prefixSum(nums.size());
  prefixSum[0] = nums.front();
  for (int i = 1; i < nums.size(); ++i) {
    prefixSum[i] = prefixSum[i - 1] + nums[i];
  }

  long long maxPerimeter = -1;
  for (int i = 1; i < nums.size() - 1; ++i) {
    if (prefixSum[i] > nums[i + 1]) {
      maxPerimeter = std::max(maxPerimeter, prefixSum[i + 1]);
    }
  }

  return maxPerimeter;
}

int main()
{
  // 2971. Find Polygon With the Largest Perimeter

  {
    std::vector<int> nums = {5, 5, 5};
    assert(largestPerimeter(nums) == 15);
  }

  {
    std::vector<int> nums = {1, 12, 1, 2, 5, 50, 3};
    assert(largestPerimeter(nums) == 12);
  }

  {
    std::vector<int> nums = {5, 5, 50};
    assert(largestPerimeter(nums) == -1);
  }

  return 0;
}
