#include <algorithm>
#include <cassert>
#include <vector>

int minMoves(std::vector<int>& nums)
{
  std::sort(nums.begin(), nums.end());

  const int medianIdx = ((nums.size() & 1) == 1) ? (nums.size() * 0.5) : ((nums.size() + 1) * 0.5);

  int moves = 0;
  for (int num: nums) {
    moves += std::abs(nums[medianIdx] - num);
  }

  return moves;
}

int main()
{
  // 462. Minimum Moves to Equal Array Elements II
  {
    std::vector<int> nums = {1, 2, 3};
    assert(minMoves(nums) == 2);
  }

  {
    std::vector<int> nums = {1, 1, 1};
    assert(minMoves(nums) == 0);
  }

  {
    std::vector<int> nums = {1, 3, 2, 5, 10};
    assert(minMoves(nums) == 12);
  }

  {
    std::vector<int> nums = {1, 10, 2, 9};
    assert(minMoves(nums) == 16);
  }
}
