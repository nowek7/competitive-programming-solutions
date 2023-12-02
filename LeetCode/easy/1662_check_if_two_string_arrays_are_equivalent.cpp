#include <cassert>
#include <iostream>
#include <string>
#include <vector>

bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2)
{
  int first = 0;
  int second = 0;
  int i = 0;
  int j = 0;
  std::string lhs;
  std::string rhs;
  while (first < word1.size() && second < word2.size()) {
    if (i == lhs.size()) {
      lhs = word1[first];
      i = 0;
    }
    if (j == rhs.size()) {
      rhs = word2[second];
      j = 0;
    }

    for (; i < lhs.size() && j < rhs.size(); ++i, ++j) {
      if (lhs[i] != rhs[j]) {
        return false;
      }
    }
    if (i == lhs.size()) {
      ++first;
    }
    if (j == rhs.size()) {
      ++second;
    }
  }

  return first == word1.size() && second == word2.size();
}

bool arrayStringsAreEqual_v2(std::vector<std::string>& word1, std::vector<std::string>& word2)
{
  auto concat = [](const std::vector<std::string>& words) -> std::string {
    std::string result;
#pragma unroll
    for (auto& w: words) {
      result += w;
    }
    return result;
  };

  return concat(word1) == concat(word2);
}

int main()
{
  // 1662. Check If Two String Arrays are Equivalent

  {
    std::vector<std::string> word1 = {"ab", "c"};
    std::vector<std::string> word2 = {"a", "bc"};
    assert(arrayStringsAreEqual(word1, word2));
    assert(arrayStringsAreEqual_v2(word1, word2));
  }

  {
    std::vector<std::string> word1 = {"a", "cb"};
    std::vector<std::string> word2 = {"ab", "c"};
    assert(arrayStringsAreEqual(word1, word2) == false);
    assert(arrayStringsAreEqual_v2(word1, word2) == false);
  }

  {
    std::vector<std::string> word1 = {"abc", "d", "defg"};
    std::vector<std::string> word2 = {"abcddefg"};
    assert(arrayStringsAreEqual(word1, word2));
    assert(arrayStringsAreEqual_v2(word1, word2));
  }

  {
    std::vector<std::string> word1 = {"abc", "d"};
    std::vector<std::string> word2 = {"abcddefg"};
    assert(arrayStringsAreEqual(word1, word2) == false);
    assert(arrayStringsAreEqual_v2(word1, word2) == false);
  }

  return 0;
}