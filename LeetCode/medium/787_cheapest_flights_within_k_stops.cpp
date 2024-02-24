#include <cassert>
#include <climits>
#include <queue>
#include <unordered_map>
#include <vector>

int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k)
{
  std::unordered_map<int, std::vector<std::pair<int, int>>> um;
  for (auto& flight: flights) {
    int from = flight[0];
    int to = flight[1];
    int price = flight[2];

    um[from].push_back({to, price});
  }

  std::vector<int> distance(n, INT_MAX);
  distance[src] = 0;

  std::queue<std::pair<int, int>> cities;
  cities.push({src, 0});
  int numStops = 0;

  while (!cities.empty() && numStops <= k) {
    int len = cities.size();
    while (len-- > 0) {
      auto [city, currPrice] = cities.front();
      cities.pop();

      if (!um.count(city)) {
        continue;
      }

      for (auto& [neighbour, price]: um[city]) {
        if (currPrice + price < distance[neighbour]) {
          distance[neighbour] = currPrice + price;
          cities.push({neighbour, distance[neighbour]});
        }
      }
    }
    ++numStops;
  }

  return distance[dst] == INT_MAX ? -1 : distance[dst];
}

int main()
{
  // 787. Cheapest Flights Within K Stops

  {
    int n = 4;
    std::vector<std::vector<int>> flights = {
      {0, 1, 100},
      {1, 2, 100},
      {2, 0, 100},
      {1, 3, 600},
      {2, 3, 200}
    };
    int src = 0;
    int dst = 3;
    int k = 1;
    assert(findCheapestPrice(n, flights, src, dst, k) == 700);
  }

  {
    int n = 3;
    std::vector<std::vector<int>> flights = {
      {0, 1, 100},
      {1, 2, 100},
      {0, 2, 500}
    };
    int src = 0;
    int dst = 2;
    int k = 1;
    assert(findCheapestPrice(n, flights, src, dst, k) == 200);
  }

  {
    int n = 3;
    std::vector<std::vector<int>> flights = {
      {0, 1, 100},
      {1, 2, 100},
      {0, 2, 500}
    };
    int src = 0;
    int dst = 2;
    int k = 0;
    assert(findCheapestPrice(n, flights, src, dst, k) == 500);
  }

  return 0;
}