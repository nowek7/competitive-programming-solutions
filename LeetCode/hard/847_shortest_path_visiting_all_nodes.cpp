#include <memory>
#include <queue>
#include <vector>

int shortestPathLength(std::vector<std::vector<int>>& graph)
{
  std::queue<std::pair<int, std::pair<int, int>>> sequence;
  int numVisitedNodeMasks = (1 << graph.size()) - 1;

  bool visitedNodes[numVisitedNodeMasks + 1][graph.size()];
  std::memset(visitedNodes, false, sizeof(visitedNodes));

  for (int i = 0; i < graph.size(); ++i) {
    int mask = (1 << i);
    sequence.push({
      i,
      {mask, 1}
    });
    visitedNodes[mask][i] = true;
  }

  while (!sequence.empty()) {
    auto entry = sequence.front();
    sequence.pop();

    int currNode = entry.first;
    int currMask = entry.second.first;
    int currLen = entry.second.second;

    if (currMask == numVisitedNodeMasks) {
      return currLen - 1;
    }

    for (int i = 0; i < graph[currNode].size(); ++i) {
      int neighbour = graph[currNode][i];
      int newMask = currMask | (1 << neighbour);

      if (visitedNodes[newMask][neighbour]) {
        continue;
      }

      sequence.push({
        neighbour,
        {newMask, currLen + 1}
      });
      visitedNodes[newMask][neighbour] = true;
    }
  }

  return -1;
}

int main()
{
  return 0;
}