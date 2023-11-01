#include <iostream>
#include <vector>

std::vector<int> findArray(std::vector<int>& pref)
{
  std::vector<int> result(pref.size(), pref.front());
  for (int i = 1; i < pref.size(); ++i) {
    result[i] = pref[i] ^ pref[i - 1];
  }

  return result;
}

void printArray(const std::vector<int>& arr)
{
  if (!arr.empty()) {
    for (int i = 0; i < arr.size() - 1; ++i) {
      std::cout << arr[i] << " ";
    }
    std::cout << arr.back() << '\n';
  }
}

int main()
{
  // 2433. Find The Original Array of Prefix Xor

  {
    std::vector<int> arr = {5, 2, 0, 3, 1};
    auto result = findArray(arr);
    printArray(result);
  }

  {
    std::vector<int> arr = {13};
    auto result = findArray(arr);
    printArray(result);
  }

  return 0;
}