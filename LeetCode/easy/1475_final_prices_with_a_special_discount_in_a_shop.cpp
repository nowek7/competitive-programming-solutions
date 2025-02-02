#include <cassert>
#include <iostream>
#include <vector>

std::vector<int> finalPrices(std::vector<int>& prices)
{
  std::vector<int> result(prices.begin(), prices.end());
  for (auto i = 0; i < prices.size() - 1; ++i) {
    for (auto j = i + 1; j < prices.size(); ++j) {
      if (prices[j] <= prices[i]) {
        result[i] -= prices[j];
        break;
      }
    }
  }

  return result;
}

int main()
{
  // 2182. Construct String With Repeat Limit

  {
    std::vector<int> prices = {8, 4, 6, 2, 3};
    const std::vector<int> result = finalPrices(prices);
    const std::vector<int> expected = {4, 2, 4, 2, 3};
    assert(result == expected);
  }

  {
    std::vector<int> prices = {1, 2, 3, 4, 5};
    const std::vector<int> result = finalPrices(prices);
    const std::vector<int> expected = {1, 2, 3, 4, 5};
    assert(result == expected);
  }

  {
    std::vector<int> prices = {10, 1, 1, 6};
    const std::vector<int> result = finalPrices(prices);
    const std::vector<int> expected = {9, 0, 1, 6};
    assert(result == expected);
  }

  return 0;
}
