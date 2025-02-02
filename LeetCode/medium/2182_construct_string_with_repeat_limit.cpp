#include <cassert>
#include <string>
#include <vector>

std::string repeatLimitedString(std::string s, int repeatLimit)
{
  std::vector<int> freq(26, 0);
  for (auto c: s) {
    ++freq[c - 'a'];
  }

  std::string result;
  int idx = 25; // 'z' character

  while (idx >= 0) {
    if (freq[idx] == 0) {
      --idx;
      continue;
    }

    const int minRepeatLimit = std::min(repeatLimit, freq[idx]);
    result.append(minRepeatLimit, idx + 'a');
    freq[idx] -= minRepeatLimit;

    if (freq[idx] > 0) {
      int j = idx - 1;
      while (j >= 0 && freq[j] == 0) {
        --j;
      }
      if (j < 0) {
        break;
      }

      result += static_cast<char>(j + 'a');
      --freq[j];
    }
  }

  return result;
}

int main()
{
  // 2182. Construct String With Repeat Limit

  {
    std::string s = "cczazcc";
    int repeatLimit = 3;
    assert(repeatLimitedString(s, repeatLimit) == "zzcccac");
  }

  {
    std::string s = "aabababcczazcc";
    int repeatLimit = 2;
    assert(repeatLimitedString(s, repeatLimit) == "zzccbccbbaa");
  }

  {
    std::string s = "abab";
    int repeatLimit = 2;
    assert(repeatLimitedString(s, repeatLimit) == "bbaa");
  }

  {
    std::string s = "abab";
    int repeatLimit = 1;
    assert(repeatLimitedString(s, repeatLimit) == "baba");
  }

  {
    std::string s = "a";
    int repeatLimit = 1;
    assert(repeatLimitedString(s, repeatLimit) == "a");
  }

  {
    std::string s = "aa";
    int repeatLimit = 2;
    assert(repeatLimitedString(s, repeatLimit) == "aa");
  }

  return 0;
}
