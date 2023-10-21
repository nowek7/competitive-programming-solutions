#include <cassert>
#include <unordered_map>
#include <vector>

bool checkIfExist(std::vector<int>& arr)
{
  std::unordered_map<int, int> store;
  for (auto entry: arr) {
    if (entry % 2 == 0 && store.count(entry / 2)) {
      return true;
    } else if (store.count(entry * 2)) {
      return true;
    } else {
      store[entry] = entry;
    }
  }

  return false;
}

int main()
{
  // 1346. Check If N and Its Double Exist

  {
    std::vector<int> nums = {10, 2, 5, 3};
    assert(checkIfExist(nums) == true);
  }

  {
    std::vector<int> nums = {3, 1, 7, 11};
    assert(checkIfExist(nums) == false);
  }

  return 0;
}
