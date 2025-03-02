#include <vector>

class ProductOfNumbers
{
  std::vector<int> numbers;

public:
  ProductOfNumbers()
  {
    numbers = {1};
  }

  void add(int num)
  {
    if (num != 0) {
      numbers.push_back(num * numbers.back());
    } else {
      numbers.clear();
      numbers.push_back(1);
    }
  }

  int getProduct(int k)
  {
    if (k > numbers.size() - 1) {
      return 0;
    } else {
      return numbers.back() / numbers[numbers.size() - k - 1];
    }
  }
};

int main()
{
  // 1352. Product of the Last K Numbers

  return 0;
}
