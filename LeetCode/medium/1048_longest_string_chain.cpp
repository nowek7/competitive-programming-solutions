#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void printWords(std::vector<std::string>& words)
{
  if (!words.empty()) {
    for (int i = 0; i < words.size() - 1; ++i) {
      std::cout << words[i] << " ";
    }
    std::cout << *words.rbegin() << '\n';
  }
}

int longestStrChain(std::vector<std::string>& words)
{
  std::sort(words.begin(), words.end(), [](const auto& lhs, const auto& rhs) {
    return lhs.size() < rhs.size();
  });

  auto isPredecessor = [](const std::string& pred, const std::string& word) -> bool {
    int j = 0;
    for (int i = 0; i < word.size(); ++i) {
      if (pred[j] == word[i]) {
        ++j;
      }
    }

    return j == pred.size();
  };

  int longestChain = 0;
  int counter = 1;
  int start = 0;
  std::string entryChain = words.front();
  for (int i = start + 1; i < words.size(); ++i) {
    const int diff = words[i].size() - entryChain.size();
    if (diff == 0) {
      continue;
    } else if (diff == 1) {
      if (isPredecessor(entryChain, words[i])) {
        ++counter;
        entryChain = words[i];
      }
    } else {
      longestChain = std::max(longestChain, counter);
      entryChain = words[++start];
      i = start + 1;
      counter = 1;
    }
  }

  longestChain = std::max(longestChain, counter);

  return longestChain;
}

int longestStrChain_v2(std::vector<std::string>& words)
{
  std::sort(words.begin(), words.end(), [](const auto& lhs, const auto& rhs) {
    return lhs.size() < rhs.size();
  });

  int maxLength = 0;
  std::unordered_map<std::string, int> store;
  for (std::string w: words) {
    int counter = 0;
    for (int i = 0; i < w.size(); ++i) {
      std::string s = w.substr(0, i) + w.substr(i + 1);
      counter = std::max(counter, store[s] + 1);
    }

    store[w] = counter;
    maxLength = std::max(maxLength, counter);
  }

  return maxLength;
}

int main()
{
  // 1048. Longest String Chain
  {
    std::vector<std::string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    std::cout << longestStrChain_v2(words) << '\n';
  }

  {
    std::vector<std::string> words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    std::cout << longestStrChain_v2(words) << '\n';
  }

  {
    std::vector<std::string> words = {"abcd", "dbqca"};
    std::cout << longestStrChain_v2(words) << '\n';
  }

  {
    std::vector<std::string> words = {
      "ksqvsyq",
      "ks",
      "kss",
      "czvh",
      "zczpzvdhx",
      "zczpzvh",
      "zczpzvhx",
      "zcpzvh",
      "zczvh",
      "gr",
      "grukmj",
      "ksqvsq",
      "gruj",
      "kssq",
      "ksqsq",
      "grukkmj",
      "grukj",
      "zczpzfvdhx",
      "gru"
    };
    std::cout << longestStrChain(words) << '\n';
  }

  return 0;
}
