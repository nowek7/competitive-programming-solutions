#include <set>
#include <unordered_map>

class NumberContainers
{
  std::unordered_map<int, int> numbers;
  std::unordered_map<int, std::set<int>> indices;

public:
  NumberContainers()
  {
  }

  void change(int index, int number)
  {
    if (numbers.find(index) != numbers.cend()) {
      const int prevNumber = numbers[index];
      indices[prevNumber].erase(index);
      if (indices[prevNumber].empty()) {
        indices.erase(prevNumber);
      }
    }

    numbers[index] = number;
    indices[number].insert(index);
  }

  int find(int number)
  {
    if (indices.find(number) != indices.cend()) {
      return *indices[number].cbegin();
    }
    return -1;
  }
};

int main()
{
  // 2349. Design a Number Container System

  return 0;
}
