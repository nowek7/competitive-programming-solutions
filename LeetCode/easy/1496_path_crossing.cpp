#include <iostream>
#include <set>
#include <string>

bool isPathCrossing(std::string path)
{
  std::set<std::pair<int, int>> visitedPoints {
    {0, 0}
  };
  std::pair<int, int> point {0, 0};
  for (auto c: path) {
    if (c == 'N') {
      ++point.first;
    }
    if (c == 'S') {
      --point.first;
    }
    if (c == 'W') {
      ++point.second;
    }
    if (c == 'E') {
      --point.second;
    }

    if (visitedPoints.count(point)) {
      return true;
    } else {
      visitedPoints.insert(point);
    }
  }

  return false;
}

int main()
{
  // 1496. Path Crossing
  std::cout << isPathCrossing("NES") << '\n';
  std::cout << isPathCrossing("NESWW") << '\n';
  std::cout << isPathCrossing("NNWWSSE") << '\n';

  return 0;
}