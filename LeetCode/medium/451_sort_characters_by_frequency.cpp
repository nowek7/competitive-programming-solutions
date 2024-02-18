#include <array>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>

std::string frequencySort(std::string s)
{
  std::array<int, 62> frequency {};
  for (char c: s) {
    if (std::islower(c)) {
      ++frequency[c - 'a'];
    } else if (std::isupper(c)) {
      ++frequency[26 + c - 'A'];
    } else {
      ++frequency[52 + c - '0'];
    }
  }

  auto comp = [](const std::pair<int, char>& lhs, const std::pair<int, char>& rhs) {
    return lhs.first < rhs.first;
  };
  std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, decltype(comp)> line(comp);
  for (int i = 0; i < 26; ++i) {
    if (frequency[i] > 0) {
      line.push({frequency[i], i + 'a'});
    }
  }
  for (int i = 26; i < 52; ++i) {
    if (frequency[i] > 0) {
      line.push({frequency[i], i + 'A' - 26});
    }
  }
  for (int i = 52; i < frequency.size(); ++i) {
    if (frequency[i] > 0) {
      line.push({frequency[i], i + '0' - 52});
    }
  }

  std::string result;
  while (!line.empty()) {
    auto entry = line.top();
    for (int i = 0; i < entry.first; ++i) {
      result += entry.second;
    }
    line.pop();
  }
  return result;
}

int main()
{
  // 451. Sort Characters By Frequency

  {
    std::string s = "tree";
    assert(frequencySort(s) == "eert");
  }

  {
    std::string s = "cccaaa";
    assert(frequencySort(s) == "aaaccc");
  }

  return 0;
}
