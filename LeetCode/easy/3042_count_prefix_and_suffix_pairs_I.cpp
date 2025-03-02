#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

int countPrefixSuffixPairs(std::vector<std::string>& words)
{
  int result = 0;

  for (auto i = 0; i < words.size() - 1; ++i) {
    const auto& lhs = words[i];
    for (auto j = i + 1; j < words.size(); ++j) {
      const auto& rhs = words[j];
      if (rhs.starts_with(lhs) && rhs.ends_with(lhs)) {
        ++result;
      }
    }
  }

  return result;
}

int main()
{
  // 1408. String Matching in an Array

  {
    std::vector<std::string> words = {"a", "aba", "ababa", "aa"};
    assert(countPrefixSuffixPairs(words) == 4);
  }

  {
    std::vector<std::string> words = {"pa", "papa", "ma", "mama"};
    assert(countPrefixSuffixPairs(words) == 2);
  }

  {
    std::vector<std::string> words = {"abab", "ab"};
    assert(countPrefixSuffixPairs(words) == 0);
  }

  return 0;
}
