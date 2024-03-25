#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

bool isIsomorphic(std::string s, std::string t)
{
  std::unordered_map<char, char> replaces;
  std::unordered_map<char, bool> used;

  for (int i = 0; i < s.length(); ++i) {
    if (replaces.count(s[i])) {
      if (replaces[s[i]] != t[i]) {
        return false;
      }
    } else {
      if (used[t[i]]) {
        return false;
      }

      replaces[s[i]] = t[i];
      used[t[i]] = true;
    }
  }

  return true;
}

bool isIsomorphic_v2(std::string s, std::string t)
{
  std::vector<int> posS(128, -1);
  std::vector<int> posT(128, -1);
  for (int i = 0; i < s.length(); ++i) {
    if (posS[s[i]] != posT[t[i]]) {
      return false;
    }

    posS[s[i]] = i;
    posT[t[i]] = i;
  }

  return true;
}

int main()
{
  // 205. Isomorphic Strings

  {
    std::string s = "egg";
    std::string t = "add";
    assert(isIsomorphic(s, t) == true);
    assert(isIsomorphic_v2(s, t) == true);
  }

  {
    std::string s = "foo";
    std::string t = "bar";
    assert(isIsomorphic(s, t) == false);
    assert(isIsomorphic_v2(s, t) == false);
  }

  {
    std::string s = "egg";
    std::string t = "add";
    assert(isIsomorphic(s, t) == true);
    assert(isIsomorphic_v2(s, t) == true);
  }

  return 0;
}
