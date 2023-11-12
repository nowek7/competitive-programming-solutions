#include <unordered_map>
#include <vector>

void solve(int u, int prev, std::unordered_map<int, std::vector<int>>& adj, std::vector<int>& result)
{
  result.push_back(u);
  for (auto& v: adj[u]) {
    if (v != prev) {
      solve(v, u, adj, result);
    }
  }
}

std::vector<int> restoreArray(std::vector<std::vector<int>>& adjacentPairs)
{
  std::unordered_map<int, std::vector<int>> adj;
  std::vector<int> result;

  for (auto& entry: adjacentPairs) {
    int u = entry.front();
    int v = entry.back();

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int start = -1;
  for (auto& [key, nums]: adj) {
    if (nums.size() == 1) {
      start = key;
      break;
    }
  }

  solve(start, -1, adj, result);
  return result;
}

int main()
{
  // 1743. Restore the Array From Adjacent Pairs

  return 0;
}
