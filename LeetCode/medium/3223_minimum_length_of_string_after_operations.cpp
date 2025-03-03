#include <array>
#include <cassert>
#include <string>

int minimumLength(std::string s)
{
  if (s.size() < 3) {
    return s.size();
  }

  std::array<int, 26> freq {0};
  for (const auto& c: s) {
    ++freq[c - 'a'];
  }

  int result = 0;
  for (auto count: freq) {
    if (count == 0) {
      continue;
    } else if (count % 2 == 0) {
      result += 2;
    } else {
      result += 1;
    }
  }

  return result;
}

int main()
{
  // 3223. Minimum Length of String After Operations

  {
    std::string s = "abaacbcbb";
    assert(minimumLength(s) == 5);
  }

  {
    std::string s = "aa";
    assert(minimumLength(s) == 2);
  }

  return 0;
}
