#include <array>
#include <cassert>
#include <string>

bool canConstruct(std::string s, int k)
{
  if (s.length() < k) {
    return false;
  }

  if (s.length() == k) {
    return true;
  }

  std::array<int, 26> alphabet {0};
  for (const auto& c: s) {
    ++alphabet[c - 'a'];
  }

  int oddCharCounts = 0;
  for (const auto& count: alphabet) {
    oddCharCounts += count & 1;
  }

  return oddCharCounts <= k;
}

int main()
{
  // 1400. Construct K Palindrome Strings

  {
    std::string s = "annabelle";
    int k = 2;
    assert(canConstruct(s, k) == true);
  }

  {
    std::string s = "leetcode";
    int k = 3;
    assert(canConstruct(s, k) == false);
  }

  {
    std::string s = "true";
    int k = 4;
    assert(canConstruct(s, k) == true);
  }

  return 0;
}
