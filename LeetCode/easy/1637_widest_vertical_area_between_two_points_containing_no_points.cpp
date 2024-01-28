#include <algorithm>
#include <cassert>
#include <climits>
#include <vector>

int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points)
{
  std::sort(points.begin(), points.end(), [](auto& lhs, auto& rhs) {
    if (lhs[0] == rhs[0]) {
      return lhs[1] < rhs[1];
    } else {
      return lhs[0] < rhs[0];
    }
  });

  int maxWide = points[1][0] - points[0][0];
  for (int i = 3; i < points.size(); ++i) {
    maxWide = std::max(maxWide, points[i][0] - points[i - 1][0]);
  }
  return maxWide;
}

int maxWidthOfVerticalArea_v2(std::vector<std::vector<int>>& points)
{
  std::vector<int> xPoints;
  xPoints.reserve(points.size());

#pragma unroll
  for (int i = 0; i < points.size(); ++i) {
    xPoints.push_back(points[i][0]);
  }
  std::sort(xPoints.begin(), xPoints.end());

  int maxWide = INT_MIN;

#pragma unroll
  for (int i = 1; i < points.size(); ++i) {
    maxWide = std::max(maxWide, xPoints[i] - xPoints[i - 1]);
  }
  return maxWide;
}

int main()
{
  // 1637. Widest Vertical Area Between Two Points Containing No Points

  {
    std::vector<std::vector<int>> points = {
      {8, 7},
      {9, 9},
      {7, 4},
      {9, 7}
    };
    assert(maxWidthOfVerticalArea(points) == 1);
    assert(maxWidthOfVerticalArea_v2(points) == 1);
  }

  {
    std::vector<std::vector<int>> points = {
      {3, 1},
      {9, 0},
      {1, 0},
      {1, 4},
      {5, 3},
      {8, 8}
    };
    assert(maxWidthOfVerticalArea(points) == 3);
    assert(maxWidthOfVerticalArea_v2(points) == 3);
  }

  return 0;
}
