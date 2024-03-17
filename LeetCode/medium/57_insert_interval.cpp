#include <cassert>
#include <vector>

std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval)
{
  std::vector<std::vector<int>> result;
  int pos = 0;

  while (pos < intervals.size() && intervals[pos][1] < newInterval[0]) {
    result.push_back(intervals[pos]);
    ++pos;
  }

  while (pos < intervals.size() && intervals[pos][0] <= newInterval[1]) {
    newInterval = {std::min(intervals[pos][0], newInterval[0]), std::max(intervals[pos][1], newInterval[1])};
    ++pos;
  }
  result.push_back(newInterval);

  while (pos < intervals.size()) {
    result.push_back(intervals[pos]);
    ++pos;
  }

  return result;
}

int main()
{
  // 57. Insert Interval

  {
    std::vector<std::vector<int>> intervals = {
      {1, 3},
      {6, 9}
    };
    std::vector<int> newInterval = {2, 5};
    std::vector<std::vector<int>> expected = {
      {1, 5},
      {6, 9}
    };
    assert(insert(intervals, newInterval) == expected);
  }

  {
    std::vector<std::vector<int>> intervals = {
      { 1,  2},
      { 3,  5},
      { 6,  7},
      { 8, 10},
      {12, 16}
    };
    std::vector<int> newInterval = {4, 8};
    std::vector<std::vector<int>> expected = {
      { 1,  2},
      { 3, 10},
      {12, 16}
    };
    assert(insert(intervals, newInterval) == expected);
  }

  return 0;
}
