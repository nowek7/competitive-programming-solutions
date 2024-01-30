#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <string>

bool closeStrings(std::string word1, std::string word2)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  if (word1.length() != word2.length()) {
    return false;
  }

  auto getDetails = [](const std::string& s) {
    std::array<int, 26> frequency {0};
    std::array<bool, 26> visible {false};
#pragma unroll
    for (char c: s) {
      ++frequency[c - 'a'];
      visible[c - 'a'] = true;
    }

    return std::pair<std::array<int, 26>, std::array<bool, 26>>(frequency, visible);
  };

  auto [freq1, visible1] = getDetails(word1);
  auto [freq2, visible2] = getDetails(word2);

  if (visible1 != visible2) {
    return false;
  }

  std::sort(freq1.begin(), freq1.end());
  std::sort(freq2.begin(), freq2.end());

  return freq1 == freq2;
}

int main()
{
  // 1657. Determine if Two Strings Are Close

  {
    std::string word1 = "abc";
    std::string word2 = "bca";
    assert(closeStrings(word1, word2) == true);
  }

  {
    std::string word1 = "a";
    std::string word2 = "aa";

    assert(closeStrings(word1, word2) == false);
  }

  {
    std::string word1 = "cabbba";
    std::string word2 = "abbccc";
    assert(closeStrings(word1, word2) == true);
  }

  return 0;
}
