#include <cassert>
#include <unordered_map>
#include <vector>

bool isValidPath(
  int source,
  int destination,
  const std::unordered_map<int, std::vector<int>>& nodes,
  std::vector<int>& visitedNodes
)
{
  if (source == destination) {
    return true;
  }

  if (nodes.empty()) {
    return false;
  }

  visitedNodes[source] = true;

  auto vertices = nodes.at(source);
  for (auto vertex: vertices) {
    if (!visitedNodes[vertex]) {
      bool isValid = isValidPath(vertex, destination, nodes, visitedNodes);
      if (isValid) {
        return true;
      }
    }
  }

  return false;
}

bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination)
{
  std::vector<int> visitedNodes(n, false);
  std::unordered_map<int, std::vector<int>> nodes;
  for (const auto& edge: edges) {
    const auto src = edge[0];
    const auto dest = edge[1];
    nodes[src].emplace_back(dest);
    nodes[dest].emplace_back(src);
  }

  return isValidPath(source, destination, nodes, visitedNodes);
}

int main()
{
  // 1971. Find if Path Exists in Graph

  {
    int n = 3;
    std::vector<std::vector<int>> edges = {
      {0, 1},
      {1, 2},
      {2, 0}
    };
    int source = 0;
    int destination = 2;
    assert(validPath(n, edges, source, destination) == true);
  }

  {
    int n = 6;
    std::vector<std::vector<int>> edges = {
      {0, 1},
      {0, 2},
      {3, 5},
      {5, 4},
      {4, 3}
    };
    int source = 0;
    int destination = 5;
    assert(validPath(n, edges, source, destination) == false);
  }

  return 0;
}
