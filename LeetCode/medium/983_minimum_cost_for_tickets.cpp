#include <cassert>
#include <cmath>
#include <vector>

int mincostTickets(std::vector<int>& days, std::vector<int>& costs)
{
  const int lastDay = days.back();
  std::vector<int> dp(lastDay + 1, 0);

  for (int d = 1, i = 0; d <= lastDay; ++d) {
    if (d < days[i]) {
      dp[d] = dp[d - 1];
    } else {
      ++i;
      dp[d] = std::min({dp[d - 1] + costs[0], dp[std::max(0, d - 7)] + costs[1], dp[std::max(0, d - 30)] + costs[2]});
    }
  }

  return dp[lastDay];
}

int main()
{
  // 983. Minimum Cost For Tickets

  {
    std::vector<int> days = {1, 4, 6, 7, 8, 20};
    std::vector<int> costs = {2, 7, 15};
    assert(mincostTickets(days, costs) == 11);
  }

  {
    std::vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    std::vector<int> costs = {2, 7, 15};
    assert(mincostTickets(days, costs) == 17);
  }

  return 0;
}
