#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int heightChecker(std::vector<int>& heights)
{
  std::vector<int> expected(heights.begin(), heights.end());
  std::sort(expected.begin(), expected.end());

  int diff = 0;
  for (int i = 0; i < heights.size(); ++i) {
    if (heights[i] != expected[i]) {
      ++diff;
    }
  }

  return diff;
}

int main()
{
  // 1051. Height Checker

  {
    std::vector<int> heights = {1, 1, 4, 2, 1, 3};
    assert(heightChecker(heights) == 3);
  }

  {
    std::vector<int> heights = {5, 1, 2, 3, 4};
    assert(heightChecker(heights) == 5);
  }

  {
    std::vector<int> heights = {1, 2, 3, 4, 5};
    assert(heightChecker(heights) == 0);
  }

  return 0;
}