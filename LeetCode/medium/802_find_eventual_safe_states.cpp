#include <cassert>
#include <vector>

bool search(
  const std::vector<std::vector<int>>& graph,
  int nodeId,
  std::vector<bool>& stackedNodes,
  std::vector<bool>& visitedNodes
)
{
  if (stackedNodes[nodeId]) {
    return true;
  }

  if (visitedNodes[nodeId]) {
    return false;
  }

  visitedNodes[nodeId] = true;
  stackedNodes[nodeId] = true;
  for (auto nextId: graph[nodeId]) {
    if (search(graph, nextId, stackedNodes, visitedNodes)) {
      return true;
    }
  }

  stackedNodes[nodeId] = false;

  return false;
}

std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph)
{
  const int n = graph.size();

  std::vector<bool> stackedNodes(n, false);
  std::vector<bool> visitedNodes(n, false);
  for (int i = 0; i < graph.size(); ++i) {
    search(graph, i, stackedNodes, visitedNodes);
  }

  std::vector<int> result;
  for (int i = 0; i < n; ++i) {
    if (!stackedNodes[i]) {
      result.push_back(i);
    }
  }

  return result;
}

int main()
{
  // 802. Find Eventual Safe States

  {
    std::vector<std::vector<int>> graph = {
      {1, 2},
      {2, 3},
      {5},
      {0},
      {5},
      {},
      {}
    };
    std::vector<int> expected = {2, 4, 5, 6};
    auto result = eventualSafeNodes(graph);
    assert(result == expected);
  }

  {
    std::vector<std::vector<int>> graph = {
      {1, 2, 3, 4},
      {1, 2},
      {3, 4},
      {0, 4},
      {}
    };
    std::vector<int> expected = {4};
    auto result = eventualSafeNodes(graph);
    assert(result == expected);
  }

  return 0;
}
