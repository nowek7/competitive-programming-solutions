#include <cassert>
#include <vector>

int getLastMoment(int n, std::vector<int>& left, std::vector<int>& right)
{
  int time = 0;
  for (int pos: left) {
    time = std::max(time, pos);
  }

  for (int pos: right) {
    time = std::max(time, n - pos);
  }

  return time;
}

int main()
{
  {
    std::vector<int> left = {4, 3};
    std::vector<int> right = {0, 1};
    assert(getLastMoment(4, left, right) == 4);
  }

  {
    std::vector<int> left = {};
    std::vector<int> right = {0, 1, 2, 3, 4, 5, 6, 7};
    assert(getLastMoment(7, left, right) == 7);
  }

  {
    std::vector<int> left = {0, 1, 2, 3, 4, 5, 6, 7};
    std::vector<int> right = {};
    assert(getLastMoment(7, left, right) == 7);
  }

  {
    std::vector<int> left = {5};
    std::vector<int> right = {4};
    assert(getLastMoment(9, left, right) == 5);
  }

  {
    std::vector<int> left = {5, 7, 6, 9, 8};
    std::vector<int> right = {0, 1, 4, 3, 2};
    assert(getLastMoment(9, left, right) == 9);
  }

  return 0;
}
