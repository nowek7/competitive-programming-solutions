#include <cassert>
#include <numeric>
#include <vector>

int pivotIndex(std::vector<int>& nums)
{
  int sum = std::accumulate(nums.begin(), nums.end(), 0);
  int leftSum = 0;
  for (int i = 0; i < nums.size(); ++i) {
    sum -= nums[i];
    if (sum == leftSum) {
      return i;
    }
    leftSum += nums[i];
  }

  return -1;
}

int main()
{
  // 724. Find Pivot Index

  {
    std::vector<int> nums = {1, 7, 3, 6, 5, 6};
    assert(pivotIndex(nums) == 3);
  }

  {
    std::vector<int> nums = {1, 2, 3};
    assert(pivotIndex(nums) == -1);
  }

  {
    std::vector<int> nums = {2, 1, -1};
    assert(pivotIndex(nums) == 0);
  }

  return 0;
}