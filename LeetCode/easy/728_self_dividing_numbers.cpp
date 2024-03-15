#include <cassert>
#include <vector>

std::vector<int> selfDividingNumbers(int left, int right)
{
  auto isSelfDividingNumber = [](int number) {
    int original = number;
    while (number > 0) {
      const int digit = number % 10;
      if (digit == 0) {
        return false;
      }

      if (original % digit != 0) {
        return false;
      }
      number /= 10;
    }

    return true;
  };

  std::vector<int> numbers;
  for (int i = left; i <= right; ++i) {
    bool isSelfDivided = isSelfDividingNumber(i);
    if (isSelfDivided) {
      numbers.push_back(i);
    }
  }

  return numbers;
}

int main()
{
  // 728. Self Dividing Numbers

  {
    int left = 1;
    int right = 22;
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22};
    assert(selfDividingNumbers(left, right) == expected);
  }

  {
    int left = 47;
    int right = 85;
    std::vector<int> expected = {48, 55, 66, 77};
    assert(selfDividingNumbers(left, right) == expected);
  }

  return 0;
}