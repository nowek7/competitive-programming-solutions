#include <iostream>
#include <numeric>
#include <vector>

int maximumWealth(std::vector<std::vector<int>>& accounts)
{
  int maxWealth = 0;
  for (const auto& customerBanks: accounts) {
    const int wealth = std::accumulate(customerBanks.begin(), customerBanks.end(), 0);
    maxWealth = std::max(maxWealth, wealth);
  }

  return maxWealth;
}

int main()
{
  // 1672. Richest Customer Wealth
  {
    std::vector<std::vector<int>> accounts = {
      {1, 2, 3},
      {3, 2, 1}
    };
    std::cout << maximumWealth(accounts) << '\n';
  }

  return 0;
}