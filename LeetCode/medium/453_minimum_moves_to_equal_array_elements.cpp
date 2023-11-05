#include <algorithm>
#include <cassert>
#include <vector>

int minMoves(std::vector<int>& nums)
{
  const int minNum = *std::min_element(nums.begin(), nums.end());
  int moves = 0;
  for (auto num: nums) {
    moves += num - minNum;
  }
  return moves;
}

int main()
{
  // 453. Minimum Moves to Equal Array Elements
  {
    std::vector<int> nums = {1, 2, 3};
    assert(minMoves(nums) == 3);
  }

  {
    std::vector<int> nums = {1, 1, 1};
    assert(minMoves(nums) == 0);
  }

  {
    std::vector<int> nums = {1, 3, 2, 5, 10};
    assert(minMoves(nums) == 16);
  }
}
