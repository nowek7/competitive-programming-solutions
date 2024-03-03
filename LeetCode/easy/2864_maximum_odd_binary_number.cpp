#include <algorithm>
#include <cassert>
#include <string>

std::string maximumOddBinaryNumber(std::string s)
{
  const int numOnes = std::count(s.begin(), s.end(), '1');
  const int numZeros = s.length() - numOnes;

  return std::string(numOnes - 1, '1') + std::string(numZeros, '0') + '1';
}

int main()
{
  // 2864. Maximum Odd Binary Number

  {
    std::string s = "010";
    assert(maximumOddBinaryNumber(s) == "001");
  }

  {
    std::string s = "1100";
    assert(maximumOddBinaryNumber(s) == "1001");
  }

  {
    std::string s = "001110";
    assert(maximumOddBinaryNumber(s) == "110001");
  }

  return 0;
}
