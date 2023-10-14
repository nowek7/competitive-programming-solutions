#include <cmath>
#include <iostream>
#include <vector>

int minCostClimbingStairs(std::vector<int>& cost)
{
  int minCost = 0;
  std::vector<int> dp(cost.size() + 1, 0);
  for (int i = 2; i < cost.size() + 1; ++i) {
    dp[i] = std::min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
  }

  return dp.back();
}

int main()
{
  // 746. Min Cost Climbing Stairs
  {
    std::vector<int> cost = {10, 15, 20};
    std::cout << minCostClimbingStairs(cost) << '\n';
  }

  {
    std::vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    std::cout << minCostClimbingStairs(cost) << '\n';
  }

  return 0;
}