#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

int minimumTime(int n, std::vector<std::vector<int>>& relations, std::vector<int>& time)
{
  std::vector<std::vector<int>> graph(n);
  std::vector<int> outDegree(n, 0);
  std::vector<int> dp(n, 0);

  for (const auto& entry: relations) {
    graph[entry[1] - 1].push_back(entry[0] - 1);
    outDegree[entry[0] - 1]++;
  }

  std::queue<int> line;

  for (int i = 0; i < n; i++) {
    if (outDegree[i] == 0) {
      line.push(i);
      dp[i] = time[i];
    }
  }

  while (!line.empty()) {
    const int course = line.front();
    line.pop();

    for (int preReq: graph[course]) {
      --outDegree[preReq];

      if (outDegree[preReq] == 0) {
        line.push(preReq);
      }
      dp[preReq] = std::max(dp[preReq], dp[course] + time[preReq]);
    }
  }

  return *max_element(dp.begin(), dp.end());
}

int main()
{
  // 2050. Parallel Courses III

  {
    std::vector<std::vector<int>> relations = {
      {1, 3},
      {2, 3}
    };
    std::vector<int> time = {3, 2, 5};
    assert(minimumTime(3, relations, time) == 8);
  }

  {
    std::vector<std::vector<int>> relations = {
      {1, 5},
      {2, 5},
      {3, 5},
      {3, 4},
      {4, 5}
    };
    std::vector<int> time = {1, 2, 3, 4, 5};
    assert(minimumTime(5, relations, time) == 12);
  }

  return 0;
}
