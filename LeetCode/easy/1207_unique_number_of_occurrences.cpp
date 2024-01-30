#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool uniqueOccurrences(std::vector<int>& arr)
{
  std::unordered_map<int, int> frequency;

  for (int number: arr) {
    ++frequency[number];
  }

  std::unordered_set<int> occurences;
  for (auto [_, value]: frequency) {
    if (occurences.count(value)) {
      return false;
    }
    occurences.insert(value);
  }

  return true;
}

int main()
{
  // 1207. Unique Number of Occurrences

  {
    std::vector<int> arr = {1, 2, 2, 1, 1, 3};
    assert(uniqueOccurrences(arr) == true);
  }

  {
    std::vector<int> arr = {1, 2};
    assert(uniqueOccurrences(arr) == false);
  }

  {
    std::vector<int> arr = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    assert(uniqueOccurrences(arr) == true);
  }

  return 0;
}
