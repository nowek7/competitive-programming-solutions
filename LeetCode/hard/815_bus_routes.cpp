#include <cassert>
#include <queue>
#include <unordered_map>
#include <vector>

int numBusesToDestination(std::vector<std::vector<int>>& routes, int source, int target)
{
  if (source == target) {
    return 0;
  }

  std::unordered_map<int, std::vector<int>> busStopToRoutes;
  for (int i = 0; i < routes.size(); ++i) {
    for (auto busStop: routes[i]) {
      busStopToRoutes[busStop].push_back(i);
    }
  }

  int numOfBuses = 0;
  std::vector<int> visitedRoutes(routes.size(), 0);
  std::queue<int> line;
  line.push(source);

  while (!line.empty()) {
    int length = line.size();
    while (length--) {
      const int busStop = line.front();
      line.pop();
      if (busStop == target) {
        return numOfBuses;
      } else {
        for (auto stop: busStopToRoutes[busStop]) {
          if (visitedRoutes[stop]) {
            continue;
          }

          visitedRoutes[stop] = 1;
          for (int nextBusStop: routes[stop]) {
            line.push(nextBusStop);
          }
        }
      }
    }
    ++numOfBuses;
  }

  return -1;
}

int main()
{
  // 815. Bus Routes
  {
    std::vector<std::vector<int>> routes = {
      {1, 2, 7},
      {3, 6, 7}
    };
    assert(numBusesToDestination(routes, 1, 6) == 2);
  }

  {
    std::vector<std::vector<int>> routes = {
      {7, 12},
      {4, 5, 15},
      {6},
      {15, 19},
      {9, 12, 13}
    };
    assert(numBusesToDestination(routes, 15, 12) == -1);
  }

  return 0;
}
