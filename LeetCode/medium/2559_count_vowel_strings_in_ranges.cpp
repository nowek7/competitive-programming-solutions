#include <cassert>
#include <string>
#include <vector>

std::vector<int> vowelStrings(std::vector<std::string>& words, std::vector<std::vector<int>>& queries)
{
  auto isVowelString = [](const std::string& s) -> bool {
    if (!(s.front() == 'a' || s.front() == 'e' || s.front() == 'i' || s.front() == 'o' || s.front() == 'u')) {
      return false;
    }

    if (!(s.back() == 'a' || s.back() == 'e' || s.back() == 'i' || s.back() == 'o' || s.back() == 'u')) {
      return false;
    }

    return true;
  };

  std::vector<int> vowelStrings(words.size(), 0);
  vowelStrings[0] = static_cast<int>(isVowelString(words[0]));

  std::vector<int> prefSum(words.size(), 0);
  prefSum[0] = vowelStrings[0];
  for (auto i = 1; i < words.size(); ++i) {
    vowelStrings[i] = static_cast<int>(isVowelString(words[i]));
    prefSum[i] = prefSum[i - 1] + vowelStrings[i];
  }

  std::vector<int> results(queries.size(), 0);
  for (auto i = 0; i < queries.size(); ++i) {
    const auto& query = queries[i];
    const auto left = query[0];
    const auto right = query[1];
    results[i] = prefSum[right] - prefSum[left] + vowelStrings[left];
  }

  return results;
}

int main()
{
  // 2559. Count Vowel Strings in Ranges

  {
    std::vector<std::string> words = {"aba", "bcb", "ece", "aa", "e"};
    std::vector<std::vector<int>> queries = {
      {0, 2},
      {1, 4},
      {1, 1}
    };
    std::vector<int> expected = {2, 3, 0};
    auto result = vowelStrings(words, queries);
    assert(result == expected);
  }

  {
    std::vector<std::string> words = {"a", "e", "i"};
    std::vector<std::vector<int>> queries = {
      {0, 2},
      {0, 1},
      {2, 2}
    };
    std::vector<int> expected = {3, 2, 1};
    auto result = vowelStrings(words, queries);
    assert(result == expected);
  }

  return 0;
}
