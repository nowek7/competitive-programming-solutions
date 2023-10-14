#include <cassert>
#include <vector>

int paintWalls(std::vector<int>& cost, std::vector<int>& time)
{
  std::vector<int> dp(cost.size() + 1, 1e9);
  dp[0] = 0;

  for (int i = 0; i < time.size(); ++i) {
    for (int j = cost.size(); j > 0; --j) {
      dp[j] = std::min(dp[j], dp[std::max(j - time[i] - 1, 0)] + cost[i]);
    }
  }
  return dp.back();
}

int main()
{
  {
    std::vector<int> cost = {1, 2, 3, 2};
    std::vector<int> time = {1, 2, 3, 2};
    assert(paintWalls(cost, time) == 3);
  }

  {
    std::vector<int> cost = {2, 3, 4, 2};
    std::vector<int> time = {1, 1, 1, 1};
    assert(paintWalls(cost, time) == 4);
  }

  return 0;
}
