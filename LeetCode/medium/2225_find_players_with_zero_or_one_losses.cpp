#include <cassert>
#include <map>
#include <vector>

std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches)
{
  std::map<int, int> ranking;
  for (const auto& m: matches) {
    const int winner = m[0];
    const int looser = m[1];
    if (ranking.count(winner) == 0) {
      ranking[winner] = 0;
    }
    ++ranking[looser];
  }

  std::vector<std::vector<int>> winners(2, std::vector<int>());
  for (auto [player, numLooses]: ranking) {
    if (numLooses > 1) {
      continue;
    }

    winners[numLooses].push_back(player);
  }

  return winners;
}

int main()
{
  // 2225. Find Players With Zero or One Losses

  {
    std::vector<std::vector<int>> matches = {
      { 1, 3},
      { 2, 3},
      { 3, 6},
      { 5, 6},
      { 5, 7},
      { 4, 5},
      { 4, 8},
      { 4, 9},
      {10, 4},
      {10, 9}
    };
    std::vector<std::vector<int>> expected = {
      {1, 2, 10},
      {4, 5, 7, 8}
    };
    std::vector<std::vector<int>> result = findWinners(matches);
    assert(result == expected);
  }

  {
    std::vector<std::vector<int>> matches = {
      {2, 3},
      {1, 3},
      {5, 4},
      {6, 4}
    };
    std::vector<std::vector<int>> expected = {
      {1, 2, 5, 6},
      {}
    };
    std::vector<std::vector<int>> result = findWinners(matches);
    assert(result == expected);
  }

  return 0;
}
