#include <array>
#include <cassert>
#include <string>

int countCharacters(std::vector<string>& words, std::string chars)
{
  std::array<int, 26> freq {0};
  for (auto c: chars) {
    ++freq[c - 'a'];
  }

  int result = 0;
  for (auto w: words) {
    bool found = true;
    std::array<int, 26> wordFreq {0};
    for (auto c: w) {
      ++wordFreq[c - 'a'];
      if (wordFreq[c - 'a'] > freq[c - 'a']) {
        found = false;
        break;
      }
    }
    if (found) {
      result += w.size();
    }
  }

  return result;
}

int main()
{
  // 1160. Find Words That Can Be Formed by Characters

  {
    std::vector<std::string> words = {"cat", "bt", "hat", "tree"};
    std::string chars = "atach";
    assert(countCharacters(words, chars) == 6);
  }

  {
    std::vector<std::string> words = {"hello", "world", "leetcode"};
    std::string chars = "welldonehoneyr";
    assert(countCharacters(words, chars) == 10);
  }

  return 0;
}
