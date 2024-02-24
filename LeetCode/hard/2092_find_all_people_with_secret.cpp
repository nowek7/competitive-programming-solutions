#include <cassert>
#include <queue>
#include <vector>

std::vector<int> findAllPeople(int n, std::vector<std::vector<int>>& meetings, int firstPerson)
{
  std::vector<std::vector<std::pair<int, int>>> adjacentPairs(n);
  for (auto entry: meetings) {
    adjacentPairs[entry[0]].push_back({entry[1], entry[2]});
    adjacentPairs[entry[1]].push_back({entry[0], entry[2]});
  }

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
  pq.push({0, 0});
  pq.push({0, firstPerson});

  std::vector<bool> visited(n, false);
  while (!pq.empty()) {
    auto [time, person] = pq.top();
    pq.pop();

    if (visited[person]) {
      continue;
    }
    visited[person] = true;

    for (auto& entry: adjacentPairs[person]) {
      if (!visited[entry.first] && entry.second >= time) {
        pq.push({entry.second, entry.first});
      }
    }
  }

  std::vector<int> result;
  result.reserve(n);
  for (int i = 0; i < visited.size(); ++i) {
    if (visited[i]) {
      result.push_back(i);
    }
  }
  result.shrink_to_fit();

  return result;
}

int main()
{
  // 2092. Find All People With Secret

  {
    int n = 6;
    std::vector<std::vector<int>> meetings = {
      {1, 2,  5},
      {2, 3,  8},
      {1, 5, 10}
    };
    int firstPerson = 1;
    std::vector<int> expected = {0, 1, 2, 3, 5};
    assert(findAllPeople(n, meetings, firstPerson) == expected);
  }

  {
    int n = 4;
    std::vector<std::vector<int>> meetings = {
      {3, 1, 3},
      {1, 2, 2},
      {0, 3, 3}
    };
    int firstPerson = 3;
    std::vector<int> expected = {0, 1, 3};
    assert(findAllPeople(n, meetings, firstPerson) == expected);
  }

  return 0;
}
