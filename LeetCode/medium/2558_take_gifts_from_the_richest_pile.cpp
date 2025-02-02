#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

long long pickGifts(std::vector<int>& gifts, int k)
{
  long long sum = std::accumulate(gifts.cbegin(), gifts.cend(), 0ll);

  std::priority_queue<int> pq {std::less<int>(), gifts};
  while (k > 0) {
    const auto original = pq.top();
    const auto changed = std::sqrt(original);
    sum = sum - original + changed;

    pq.pop();
    pq.push(changed);
    --k;
  }

  return sum;
}

int main()
{
  // 2558. Take Gifts From the Richest Pile

  {
    std::vector<int> gifts = {25, 64, 9, 4, 100};
    int k = 4;
    assert(pickGifts(gifts, k) == 29);
  }

  {
    std::vector<int> gifts = {1, 1, 1, 1};
    int k = 4;
    assert(pickGifts(gifts, k) == 4);
  }

  return 0;
}