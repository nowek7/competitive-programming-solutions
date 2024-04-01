#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

std::string kthDistinct(std::vector<std::string>& arr, int k)
{
  std::unordered_map<std::string, int> frequency;
  for (auto entry: arr) {
    ++frequency[entry];
  }

  int counter = 0;
  for (std::size_t i = 0; i < arr.size(); ++i) {
    if (frequency[arr[i]] == 1) {
      ++counter;
    }

    if (counter == k) {
      return arr[i];
    }
  }

  return "";
}

int main()
{
  // 2053. Kth Distinct String in an Array

  {
    std::vector<std::string> arr = {"d", "b", "c", "b", "c", "a"};
    assert(kthDistinct(arr, 2) == "a");
  }

  {
    std::vector<std::string> arr = {"aaa", "aa", "a"};
    assert(kthDistinct(arr, 1) == "aaa");
  }

  {
    std::vector<std::string> arr = {"a", "b", "a"};
    assert(kthDistinct(arr, 3) == "");
  }

  return 0;
}
