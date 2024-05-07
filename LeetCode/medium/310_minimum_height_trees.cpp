#include <cassert>
#include <queue>
#include <vector>

std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges)
{
  if (n == 1) {
    return {0};
  }

  std::vector<std::vector<int>> graph(n);
  std::vector<int> degree(n, 0);
  for (const auto& edge: edges) {
    graph[edge[0]].push_back(edge[1]);
    graph[edge[1]].push_back(edge[0]);
    ++degree[edge[0]];
    ++degree[edge[1]];
  }

  std::queue<int> line;
  for (int i = 0; i < n; ++i) {
    if (degree[i] == 1) {
      line.push(i);
    }
  }

  std::vector<int> result;
  int left = n;
  while (!line.empty()) {
    int length = line.size();
    left -= length;
    for (int i = 0; i < length; ++i) {
      int node = line.front();
      line.pop();

      if (left == 0) {
        result.push_back(node);
      }

      for (auto vertex: graph[node]) {
        --degree[vertex];
        if (degree[vertex] == 1) {
          line.push(vertex);
        }
      }
    }
  }

  return result;
}

int main()
{
  // 310. Minimum Height Trees

  {
    std::vector<std::vector<int>> edges = {
      {1, 0},
      {1, 2},
      {1, 3}
    };
    std::vector<int> expected = {1};
    std::vector<int> results = findMinHeightTrees(4, edges);
    assert(results == expected);
  }

  {
    std::vector<std::vector<int>> edges = {
      {3, 0},
      {3, 1},
      {3, 2},
      {3, 4},
      {5, 4}
    };
    std::vector<int> expected = {3, 4};
    std::vector<int> results = findMinHeightTrees(6, edges);
    assert(results == expected);
  }

  return 0;
}
