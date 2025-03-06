#include <cassert>
#include <cmath>
#include <limits>
#include <string>

int minimumRecolors(std::string blocks, int k)
{
  int minNum = std::numeric_limits<int>::max();
  for (auto i = 0; i < blocks.length(); ++i) {
    if (i + k > blocks.length()) {
      continue;
    }

    int num = 0;
    for (auto j = i; j < i + k; ++j) {
      if (blocks[j] == 'W') {
        ++num;
      }
    }
    minNum = std::min(minNum, num);
    if (minNum == 0) {
      break;
    }
  }

  return minNum;
}

int main()
{
  // 2379. Minimum Recolors to Get K Consecutive Black Blocks

  {
    std::string blocks = "WBBWWBBWBW";
    int k = 7;
    assert(minimumRecolors(blocks, k) == 3);
  }

  {
    std::string blocks = "WBWBBBW";
    int k = 2;
    assert(minimumRecolors(blocks, k) == 0);
  }

  return 0;
}
