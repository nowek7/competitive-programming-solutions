#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

int maxTwoEvents(std::vector<std::vector<int>>& events)
{
  int result = 0;
  std::sort(events.begin(), events.end());

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

  int tmpValue = 0;
  for (auto& e: events) {
    int start = e[0];
    int end = e[1];
    int value = e[2];

    while (!pq.empty() && pq.top().first < start) {
      tmpValue = std::max(tmpValue, pq.top().second);
      pq.pop();
    }

    result = std::max(result, tmpValue + value);

    pq.push({end, value});
  }

  return result;
}

int main()
{
  // 2054. Two Best Non-Overlapping Events

  {
    std::vector<std::vector<int>> events = {
      {1, 3, 2},
      {4, 5, 2},
      {2, 4, 3}
    };
    assert(maxTwoEvents(events) == 4);
  }

  {
    std::vector<std::vector<int>> events = {
      {1, 3, 2},
      {4, 5, 2},
      {1, 5, 5}
    };
    assert(maxTwoEvents(events) == 5);
  }

  {
    std::vector<std::vector<int>> events = {
      {1, 5, 3},
      {1, 5, 1},
      {6, 6, 5}
    };
    assert(maxTwoEvents(events) == 8);
  }

  {
    std::vector<std::vector<int>> events = {
      {1, 5, 3}
    };
    assert(maxTwoEvents(events) == 3);
  }

  {
    std::vector<std::vector<int>> events = {
      {1,  5, 3},
      {6, 10, 5}
    };
    assert(maxTwoEvents(events) == 8);
  }

  {
    std::vector<std::vector<int>> events = {
      {1, 5, 3},
      {2, 3, 3},
      {3, 4, 1}
    };
    assert(maxTwoEvents(events) == 3);
  }

  {
    std::vector<std::vector<int>> events = {
      {1, 5, 3},
      {2, 3, 4},
      {3, 4, 1}
    };
    assert(maxTwoEvents(events) == 4);
  }

  {
    std::vector<std::vector<int>> events = {
      {1, 2, 3},
      {3, 4, 3},
      {5, 6, 4}
    };
    assert(maxTwoEvents(events) == 7);
  }

  return 0;
}
