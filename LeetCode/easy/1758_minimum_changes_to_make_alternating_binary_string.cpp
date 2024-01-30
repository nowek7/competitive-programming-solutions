#include <cassert>
#include <string>

int minOperations(std::string s)
{
  const int len = s.length();
  int cost10 = 0;
  for (int i = 0; i < len; ++i) {
    if (s[i] - '0' == i % 2) {
      ++cost10;
    }
  }

  return std::min(cost10, static_cast<int>(len - cost10));
}

int main()
{
  // 1758. Minimum Changes To Make Alternating Binary String

  {
    std::string s = "0100";
    assert(minOperations(s) == 1);
  }

  {
    std::string s = "10";
    assert(minOperations(s) == 0);
  }

  {
    std::string s = "1111";
    assert(minOperations(s) == 2);
  }

  return 0;
}
