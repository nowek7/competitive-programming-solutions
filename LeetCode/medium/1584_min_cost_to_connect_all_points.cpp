#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

int find(std::vector<int>& parent, int x)
{
  if (parent.at(x) == x) {
    return x;
  } else {
    parent[x] = find(parent, parent[x]);
    return parent[x];
  }
}

int minCostConnectPoints(std::vector<std::vector<int>>& points)
{
  std::vector<int> parent(points.size());
  std::iota(parent.begin(), parent.end(), 0);
  std::vector<std::pair<int, std::pair<int, int>>> edges;

  auto manhattanDistance = [](const std::vector<int>& x, const std::vector<int>& y) {
    return std::abs(x.at(0) - y.at(0)) + std::abs(x.at(1) - y.at(1));
  };

  // Compute Manhattan distance between each point
  for (int i = 0; i < points.size(); ++i) {
    for (int j = i + 1; j < points.size(); ++j) {
      int cost = manhattanDistance(points.at(i), points.at(j));
      edges.push_back({
        cost,
        {i, j}
      });
    }
  }
  std::sort(edges.begin(), edges.end());

  int minCost = 0;
  int numEdges = 0;
  for (int i = 0; i < edges.size(); i++) {
    auto& edge = edges[i];
    int& cost = edge.first;

    auto& [x, y] = edge.second;
    if (find(parent, x) != find(parent, y)) {
      minCost += cost;
      parent[find(parent, x)] = find(parent, y);
      ++numEdges;
    }

    if (numEdges == points.size() - 1) {
      break;
    }
  }

  return minCost;
}

int main()
{
  {
    std::vector<std::vector<int>> points = {
      {0,  0},
      {2,  2},
      {3, 10},
      {5,  2},
      {7,  0}
    };
    std::cout << minCostConnectPoints(points) << '\n';
  }
  std::cout << "-------------" << '\n';
  {
    std::vector<std::vector<int>> points = {
      { 3, 12},
      {-2,  5},
      {-4,  1}
    };
    std::cout << minCostConnectPoints(points) << '\n';
  }

  return 0;
}