#include <algorithm>
#include <cassert>
#include <vector>

int getWinner(std::vector<int>& arr, int k)
{
  if (k == 1) {
    return std::max(arr[0], arr[1]);
  }

  if (k >= arr.size()) {
    return *std::max_element(arr.begin(), arr.end());
  }

  int currWinner = arr.front();
  int wins = 0;
  for (int i = 1; i < arr.size() && wins < k; ++i) {
    if (currWinner > arr[i]) {
      ++wins;
    } else {
      currWinner = arr[i];
      wins = 1;
    }
  }

  return currWinner;
}

int main()
{
  // 1535. Find the Winner of an Array Game
  {
    std::vector<int> arr = {2, 1, 3, 5, 4, 6, 7};
    assert(getWinner(arr, 2) == 5);
  }

  {
    std::vector<int> arr = {3, 2, 1};
    assert(getWinner(arr, 10) == 3);
  }
}
