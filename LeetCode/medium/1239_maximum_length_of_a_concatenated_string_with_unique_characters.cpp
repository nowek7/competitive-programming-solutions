#include <array>
#include <cassert>
#include <string>
#include <vector>

int maxLength(std::vector<std::string>& arr)
{
  auto isUnique = [](const std::string& s) -> bool {
    if (s.length() > 26) {
      return false;
    }
    std::array<int, 26> freq {0};
    for (char c: s) {
      ++freq[c - 'a'];
      if (freq[c - 'a'] > 1) {
        return false;
      }
    }
    return true;
  };

  int maxLen = 0;
  std::vector<std::string> concatenatedStr {""};
  for (int i = 0; i < arr.size(); ++i) {
    const std::string& str = arr[i];
    if (!isUnique(str)) {
      continue;
    }

    std::vector<std::string> strSeq;
    for (const auto& s: concatenatedStr) {
      std::string tmp = str + s;
      if (isUnique(tmp)) {
        strSeq.push_back(tmp);
        maxLen = std::max(maxLen, static_cast<int>(tmp.length()));
      }
    }

    concatenatedStr.insert(concatenatedStr.end(), strSeq.begin(), strSeq.end());
  }

  return maxLen;
}

int main()
{
  // 1239. Maximum Length of a Concatenated String with Unique Characters

  {
    std::vector<std::string> arr = {"un", "iq", "ue"};
    assert(maxLength(arr) == 4);
  }

  {
    std::vector<std::string> arr = {"cha", "r", "act", "ers"};
    assert(maxLength(arr) == 6);
  }

  {
    std::vector<std::string> arr = {"abcdefghijklmnopqrstuvwxyz"};
    assert(maxLength(arr) == 26);
  }

  return 0;
}
