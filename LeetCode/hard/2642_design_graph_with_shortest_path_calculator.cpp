#include <climits>
#include <queue>
#include <vector>

class Graph
{
private:
  int m_numNodes;
  std::vector<std::vector<std::pair<int, int>>> m_graph;

public:
  Graph(int n, std::vector<std::vector<int>>& edges):
    m_numNodes(n),
    m_graph(n)
  {
    for (auto& e: edges) {
      addEdge(e);
    }
  }

  void addEdge(std::vector<int> edge)
  {
    m_graph[edge[0]].emplace_back(edge[1], edge[2]);
  }

  int shortestPath(int node1, int node2)
  {
    std::vector<int> costNodes(m_numNodes, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> heap;

    costNodes[node1] = 0;
    heap.push({0, node1});
    while (!heap.empty()) {
      auto [currCost, currNode] = heap.top();
      heap.pop();
      for (auto [nextNode, nextCost]: m_graph[currNode]) {
        int cost = currCost + nextCost;
        if (cost >= costNodes[nextNode]) {
          continue;
        }
        costNodes[nextNode] = cost;
        heap.push({cost, nextNode});
      }
    }

    if (costNodes[node2] == INT_MAX) {
      return -1;
    } else {
      return costNodes[node2];
    }
  }
};

int main()
{
  // 2642. Design Graph With Shortest Path Calculator

  return 0;
}
