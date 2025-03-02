#include <cassert>
#include <cmath>
#include <vector>

int findComplement(int num)
{
  std::vector<bool> bits;
  while (num > 0) {
    bits.push_back(!(num % 2));
    num /= 2;
  }

  int result = 0;

  int i = bits.size() - 1;
  while (i >= 0) {
    if (bits[i]) {
      result += std::pow(2, i);
    }
    --i;
  }

  return result;
}

int main()
{
  // 476. Number Complement

  {
    assert(findComplement(1) == 0);
  }

  {
    assert(findComplement(2) == 1);
  }

  {
    assert(findComplement(5) == 2);
  }

  return 0;
}
