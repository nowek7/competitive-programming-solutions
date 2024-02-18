#include <cassert>
#include <queue>
#include <unordered_map>
#include <vector>

int findLeastNumOfUniqueInts(std::vector<int>& arr, int k)
{
  std::unordered_map<int, int> store;

  for (int i = 0; i < arr.size(); ++i) {
    ++store[arr[i]];
  }

  auto comp = [](std::pair<int, int>& lhs, std::pair<int, int>& rhs) {
    return lhs.second > rhs.second;
  };

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> pq(
    store.begin(),
    store.end(),
    comp
  );

  while (k > 0 && !pq.empty()) {
    auto [_, freq] = pq.top();

    pq.pop();

    k -= freq;
  }

  return k == 0 ? pq.size() : pq.size() + 1;
}

int main()
{
  // 1481. Least Number of Unique Integers after K Removals

  {
    std::vector<int> arr = {5, 5, 4};
    assert(findLeastNumOfUniqueInts(arr, 1) == 1);
  }

  {
    std::vector<int> arr = {4, 3, 1, 1, 3, 3, 2};
    assert(findLeastNumOfUniqueInts(arr, 3) == 2);
  }

  return 0;
}
