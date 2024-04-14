#include <algorithm>
#include <array>
#include <cassert>
#include <vector>

void sortColors(std::vector<int>& nums)
{
  std::array<int, 3> counter {0};
  for (auto number: nums) {
    ++counter[number];
  }

  std::fill_n(nums.begin(), counter[0], 0);
  std::fill_n(nums.begin() + counter[0], counter[1], 1);
  std::fill_n(nums.begin() + counter[0] + counter[1], counter[2], 2);
}

int main()
{
  // 75. Sort Colors

  {
    std::vector<int> colors = {2, 0, 2, 1, 1, 0};
    std::vector<int> expected = {0, 0, 1, 1, 2, 2};
    sortColors(colors);
    assert(colors == expected);
  }

  {
    std::vector<int> colors = {0};
    std::vector<int> expected = {0};
    sortColors(colors);
    assert(colors == expected);
  }

  {
    std::vector<int> colors = {2, 1};
    std::vector<int> expected = {1, 2};
    sortColors(colors);
    assert(colors == expected);
  }

  {
    std::vector<int> colors = {2, 1, 0};
    std::vector<int> expected = {0, 1, 2};
    sortColors(colors);
    assert(colors == expected);
  }

  return 0;
}
