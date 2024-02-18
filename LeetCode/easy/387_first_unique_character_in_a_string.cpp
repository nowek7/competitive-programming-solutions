#include <array>
#include <cassert>
#include <string>

int firstUniqChar(std::string s)
{
  std::array<int, 26> indicies;
  for (int i = 0; i < s.length(); ++i) {
    ++indicies[s[i] - 'a'];
  }

  for (int i = 0; i < s.length(); ++i) {
    if (indicies[s[i] - 'a'] == 1) {
      return i;
    }
  }

  return -1;
}

int main()
{
  // 387. First Unique Character in a String

  {
    std::string s = "leetcode";
    assert(firstUniqChar(s) == 0);
  }

  {
    std::string s = "loveleetcode";
    assert(firstUniqChar(s) == 2);
  }

  {
    std::string s = "aabb";
    assert(firstUniqChar(s) == -1);
  }

  return 0;
}
