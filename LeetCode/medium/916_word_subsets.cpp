#include <array>
#include <cassert>
#include <string>
#include <vector>

std::vector<std::string> wordSubsets(std::vector<std::string>& words1, std::vector<std::string>& words2)
{
  auto countChar = [](const std::string& s) -> std::array<int, 26> {
    std::array<int, 26> counter {0};
    for (auto c: s) {
      ++counter[c - 'a'];
    }
    return counter;
  };

  std::array<int, 26> alphabet {0};
  for (const auto& w: words2) {
    auto tmpCounter = countChar(w);
    for (auto i = 0; i < 26; ++i) {
      alphabet[i] = std::max(alphabet[i], tmpCounter[i]);
    }
  }

  std::vector<std::string> result;
  result.reserve(words1.size());

  for (const auto& w: words1) {
    bool isUniversal = true;
    auto tmpCounter = countChar(w);
    for (auto i = 0; i < 26; ++i) {
      if (tmpCounter[i] < alphabet[i]) {
        isUniversal = false;
        break;
      }
    }
    if (isUniversal) {
      result.push_back(std::move(w));
    }
  }

  result.shrink_to_fit();

  return result;
}

int main()
{
  // 916. Word Subsets

  {
    std::vector<std::string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    std::vector<std::string> words2 = {"e", "o"};
    std::vector<std::string> expected = {"facebook", "google", "leetcode"};
    auto result = wordSubsets(words1, words2);
    assert(result == expected);
  }

  {
    std::vector<std::string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    std::vector<std::string> words2 = {"lc", "eo"};
    std::vector<std::string> expected = {"leetcode"};
    auto result = wordSubsets(words1, words2);
    assert(result == expected);
  }

  {
    std::vector<std::string> words1 = {"acaac", "cccbb", "aacbb", "caacc", "bcbbb"};
    std::vector<std::string> words2 = {"c", "cc", "b"};
    std::vector<std::string> expected = {"cccbb"};
    auto result = wordSubsets(words1, words2);
    assert(result == expected);
  }

  return 0;
}
