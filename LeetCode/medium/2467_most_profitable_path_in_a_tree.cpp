#include <cassert>
#include <climits>
#include <unordered_map>
#include <vector>

class Solution
{
public:
  int mostProfitablePath(std::vector<std::vector<int>>& edges, int bob, std::vector<int>& amount)
  {
    int n = amount.size();
    tree.resize(n);
    visited.assign(n, false);

    // Form tree with edges
    for (std::vector<int> edge: edges) {
      tree[edge[0]].push_back(edge[1]);
      tree[edge[1]].push_back(edge[0]);
    }

    findBobPath(bob, 0);

    visited.assign(n, false);
    findAlicePath(0, 0, 0, amount);

    return maxIncome;
  }

private:
  std::unordered_map<int, int> bobPath;
  std::vector<bool> visited;
  std::vector<std::vector<int>> tree;
  int maxIncome = INT_MIN;

  bool findBobPath(int sourceNode, int time)
  {
    bobPath[sourceNode] = time;
    visited[sourceNode] = true;

    if (sourceNode == 0) {
      return true;
    }

    for (int adjacentNode: tree[sourceNode]) {
      if (!visited[adjacentNode] && findBobPath(adjacentNode, time + 1)) {
        return true;
      }
    }

    bobPath.erase(sourceNode);
    return false;
  }

  void findAlicePath(int sourceNode, int time, int income, std::vector<int>& amount)
  {
    visited[sourceNode] = true;

    if (bobPath.find(sourceNode) == bobPath.end() || time < bobPath[sourceNode]) {
      income += amount[sourceNode];
    } else if (time == bobPath[sourceNode]) {
      income += (amount[sourceNode] / 2);
    }

    if (tree[sourceNode].size() == 1 && sourceNode != 0) {
      maxIncome = std::max(maxIncome, income);
    }

    for (int adjacentNode: tree[sourceNode]) {
      if (!visited[adjacentNode]) {
        findAlicePath(adjacentNode, time + 1, income, amount);
      }
    }
  }
};

int main()
{
  // 2467. Most Profitable Path in a Tree

  {
    std::vector<std::vector<int>> edges = {
      {0, 1},
      {1, 2},
      {1, 3},
      {3, 4}
    };
    int bob = 3;
    std::vector<int> amount = {-2, 4, 2, -4, 6};
    assert(Solution().mostProfitablePath(edges, bob, amount) == 6);
  }

  {
    std::vector<std::vector<int>> edges = {
      {0, 1}
    };
    int bob = 1;
    std::vector<int> amount = {-7280, 2350};
    assert(Solution().mostProfitablePath(edges, bob, amount) == -7280);
  }

  return 0;
}
