#include <iostream>
#include <vector>

void duplicateZeros(std::vector<int>& arr)
{
  std::vector<int> result;
  for (int i = 0; i < arr.size(); ++i) {
    result.push_back(arr.at(i));
    if (arr.at(i) == 0) {
      result.push_back(0);
    }
  }

  for (int i = 0; i < arr.size(); ++i) {
    arr[i] = result[i];
  }
  result.clear();
}

void print(std::vector<int>& sequence)
{
  if (!sequence.empty()) {
    for (int i = 0; i < sequence.size() - 1; ++i) {
      std::cout << sequence.at(i) << " ";
    }
    std::cout << *sequence.rbegin() << '\n';
  }
}

int main()
{
  // 1089. Duplicate Zeros
  {
    std::vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
    duplicateZeros(arr);
    print(arr);
  }

  {
    std::vector<int> arr = {1, 2, 3};
    duplicateZeros(arr);
    print(arr);
  }

  return 0;
}