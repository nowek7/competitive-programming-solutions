#include <cassert>
#include <unordered_map>
#include <vector>

std::vector<int> queryResults(int limit, std::vector<std::vector<int>>& queries)
{
  std::vector<int> result(queries.size(), 0);

  std::unordered_map<int, int> colors;
  std::unordered_map<int, int> coloredBalls;
  for (auto i = 0; i < queries.size(); ++i) {
    const int idx = queries[i][0];
    const int color = queries[i][1];

    if (coloredBalls.find(idx) != coloredBalls.cend()) {
      int prevColor = coloredBalls[idx];
      --colors[prevColor];
      if (colors[prevColor] == 0) {
        colors.erase(prevColor);
      }
    }

    coloredBalls[idx] = color;
    colors[color]++;

    result[i] = colors.size();
  }

  return result;
}

int main()
{
  // 3160. Find the Number of Distinct Colors Among the Balls

  {
    int limit = 4;
    std::vector<std::vector<int>> queries = {
      {1, 4},
      {2, 5},
      {1, 3},
      {3, 4}
    };
    std::vector<int> expected = {1, 2, 2, 3};
    assert(queryResults(limit, queries) == expected);
  }

  {
    int limit = 4;
    std::vector<std::vector<int>> queries = {
      {0, 1},
      {1, 2},
      {2, 2},
      {3, 4},
      {4, 5}
    };
    std::vector<int> expected = {1, 2, 2, 3, 4};
    assert(queryResults(limit, queries) == expected);
  }

  return 0;
}
