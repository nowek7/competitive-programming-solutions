#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int buyChoco(std::vector<int>& prices, int money)
{
  std::pair<int, int> chocolates {prices[0], prices[1]};
#pragma unroll
  for (int i = 2; i < prices.size(); ++i) {
    if (prices[i] <= chocolates.first) {
      chocolates.second = std::min(chocolates.first, chocolates.second);
      chocolates.first = prices[i];
    } else {
      chocolates.second = std::min(chocolates.second, prices[i]);
    }
  }
  const int leftover = money - chocolates.first - chocolates.second;
  return leftover < 0 ? money : leftover;
}

int buyChoco_v2(std::vector<int>& prices, int money)
{
  std::sort(prices.begin(), prices.end());
  int leftover = money - prices[0];
  if (leftover <= 0) {
    return money;
  }
  leftover -= prices[1];
  return leftover < 0 ? money : leftover;
}

int main()
{
  // 2706. Buy Two Chocolates

  {
    std::vector<int> prices = {1, 2, 2};
    int money = 3;
    assert(buyChoco(prices, money) == 0);
    assert(buyChoco_v2(prices, money) == 0);
  }

  {
    std::vector<int> prices = {3, 2, 3};
    int money = 3;
    assert(buyChoco(prices, money) == 3);
    assert(buyChoco_v2(prices, money) == 3);
  }

  return 0;
}
