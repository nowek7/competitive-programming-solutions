#include <algorithm>
#include <array>
#include <cassert>
#include <vector>

int leastInterval(std::vector<char>& tasks, int n)
{
  std::array<int, 26> tasksFrequency {0};
  int maxFrequency = 0;
  for (auto c: tasks) {
    ++tasksFrequency[c - 'A'];
    maxFrequency = std::max(maxFrequency, tasksFrequency[c - 'A']);
  }

  const int numMaxFreq = std::count(tasksFrequency.begin(), tasksFrequency.end(), maxFrequency);
  const int time = (maxFrequency - 1) * (n + 1) + numMaxFreq;

  return std::max(time, static_cast<int>(tasks.size()));
}

int main()
{
  // 621. Task Scheduler

  {
    std::vector<char> tasks = {"A", "A", "A", "B", "B", "B"};
    int n = 2;
    assert(leastInterval(tasks, n) == 8);
  }

  {
    std::vector<char> tasks = {"A", "C", "A", "B", "D", "B"};
    int n = 1;
    assert(leastInterval(tasks, n) == 6);
  }

  {
    std::vector<char> tasks = {"A", "A", "A", "B", "B", "B"};
    int n = 3;
    assert(leastInterval(tasks, n) == 10);
  }

  return 0;
}
