#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

std::vector<std::string> stringMatching(std::vector<std::string>& words)
{
  std::sort(words.begin(), words.end(), [](const auto& lhs, const auto& rhs) {
    if (lhs.size() != rhs.size()) {
      return lhs.size() < rhs.size();
    }
    return lhs < rhs;
  });

  std::vector<std::string> result;
  for (auto i = 0; i < words.size() - 1; ++i) {
    const auto& lhs = words[i];
    for (auto j = i + 1; j < words.size(); ++j) {
      const auto& rhs = words[j];
      if (rhs.find(lhs) != std::string::npos) {
        result.push_back(lhs);
        break;
      }
    }
  }

  return result;
}

int main()
{
  // 1408. String Matching in an Array

  {
    std::vector<std::string> words = {"mass", "as", "hero", "superhero"};
    std::vector<std::string> expected = {"as", "hero"};
    std::vector<std::string> result = stringMatching(words);
    assert(expected == result);
  }

  {
    std::vector<std::string> words = {"leetcode", "et", "code"};
    std::vector<std::string> expected = {"et", "code"};
    std::vector<std::string> result = stringMatching(words);

    assert(expected == result);
  }

  {
    std::vector<std::string> words = {"blue", "green", "bu"};
    std::vector<std::string> expected = {};
    std::vector<std::string> result = stringMatching(words);
    assert(expected == result);
  }

  return 0;
}
