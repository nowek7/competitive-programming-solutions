#include <cassert>
#include <stack>
#include <vector>

std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
{
  std::vector<int> days(temperatures.size(), 0);
  std::stack<int> heap;
  for (int i = 0; i < temperatures.size(); ++i) {
    while (!heap.empty() && temperatures[heap.top()] < temperatures[i]) {
      days[heap.top()] = i - heap.top();
      heap.pop();
    }

    heap.push(i);
  }

  return days;
}

int main()
{
  // 739. Daily Temperatures

  {
    std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> expected = {1, 1, 4, 2, 1, 1, 0, 0};
    assert(dailyTemperatures(temperatures) == expected);
  }

  {
    std::vector<int> temperatures = {30, 40, 50, 60};
    std::vector<int> expected = {1, 1, 1, 0};
    assert(dailyTemperatures(temperatures) == expected);
  }

  {
    std::vector<int> temperatures = {30, 60, 90};
    std::vector<int> expected = {1, 1, 0};
    assert(dailyTemperatures(temperatures) == expected);
  }

  return 0;
}
