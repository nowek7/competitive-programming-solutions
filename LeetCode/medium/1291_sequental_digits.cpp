#include <cassert>
#include <queue>
#include <vector>

std::vector<int> sequentialDigits(int low, int high)
{
  std::vector<int> result;

  std::queue<int> digits;
  for (int i = 1; i < 10; ++i) {
    digits.push(i);
  }

  while (!digits.empty()) {
    long long number = digits.front();
    digits.pop();

    if (low <= number && number <= high) {
      result.push_back(number);
    }

    int rem = number % 10;
    if (rem < 9) {
      number = (number * 10) + rem + 1;
      digits.push(number);
    }
  }

  return result;
}

int main()
{
  // 1291. Sequential Digits

  {
    std::vector<int> result = sequentialDigits(100, 300);
    std::vector<int> expected = {123, 234};
    assert(result == expected);
  }

  {
    std::vector<int> result = sequentialDigits(1000, 13000);
    std::vector<int> expected = {1234, 2345, 3456, 4567, 5678, 6789, 12345};
    assert(result == expected);
  }

  return 0;
}
