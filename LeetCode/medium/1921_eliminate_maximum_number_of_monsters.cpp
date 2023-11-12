#include <cassert>
#include <cmath>
#include <vector>

int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed)
{
  const int n = dist.size();
  for (int i = 0; i < n; ++i) {
    dist[i] = std::ceil(static_cast<double>(dist[i]) / speed[i]);
    speed[i] = 0;
  }

  for (int time: dist) {
    if (time >= n) {
      continue;
    }
    speed[time] += 1;
  }

  for (int i = 1; i < n; ++i) {
    speed[i] += speed[i - 1];
    if (speed[i] > i) {
      return i;
    }
  }
  return n;
}

int main()
{
  // 1921. Eliminate Maximum Number of Monsters

  {
    std::vector<int> dist = {1, 3, 4};
    std::vector<int> speed = {1, 1, 1};
    assert(eliminateMaximum(dist, speed) == 3);
  }

  {
    std::vector<int> dist = {1, 1, 2, 3};
    std::vector<int> speed = {1, 1, 1, 1};
    assert(eliminateMaximum(dist, speed) == 1);
  }

  {
    std::vector<int> dist = {3, 2, 4};
    std::vector<int> speed = {5, 3, 2};
    assert(eliminateMaximum(dist, speed) == 1);
  }

  {
    std::vector<int> dist = {4, 3, 4};
    std::vector<int> speed = {1, 1, 2};
    assert(eliminateMaximum(dist, speed) == 3);
  }

  return 0;
}