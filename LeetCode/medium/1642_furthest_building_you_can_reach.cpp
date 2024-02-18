#include <cassert>
#include <queue>
#include <vector>

int furthestBuilding(std::vector<int>& heights, int bricks, int ladders)
{
  int idx = 0;
  std::priority_queue<int> pq;
  for (int i = 0; i < heights.size() - 1; ++i, ++idx) {
    const int diff = heights[i + 1] - heights[i];
    if (diff <= 0) {
      continue;
    }

    pq.push(diff);
    bricks -= diff;
    if (bricks < 0) {
      bricks += pq.top();
      pq.pop();
      --ladders;
    }
    if (ladders < 0) {
      break;
    }
  }

  return idx;
}

int main()
{
  // 1642. Furthest Building You Can Reach

  {
    std::vector<int> heights = {4, 2, 7, 6, 9, 14, 12};
    int bricks = 5;
    int ladders = 1;
    assert(furthestBuilding(heights, bricks, ladders) == 4);
  }

  {
    std::vector<int> heights = {4, 12, 2, 7, 3, 18, 20, 3, 19};
    int bricks = 10;
    int ladders = 2;
    assert(furthestBuilding(heights, bricks, ladders) == 7);
  }

  {
    std::vector<int> heights = {14, 3, 19, 3};
    int bricks = 17;
    int ladders = 0;
    assert(furthestBuilding(heights, bricks, ladders) == 3);
  }

  return 0;
}
