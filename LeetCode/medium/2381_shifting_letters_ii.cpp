#include <cassert>
#include <string>
#include <vector>

std::string shiftingLetters(std::string s, std::vector<std::vector<int>>& shifts)
{
  std::vector<int> moves(s.size(), 0);

  for (const auto& entry: shifts) {
    const auto start = entry[0];
    const auto end = entry[1];
    const auto isForward = static_cast<bool>(entry[2] == 1);
    if (isForward) {
      ++moves[start];
      if (end + 1 < s.size()) {
        --moves[end + 1];
      }
    } else {
      --moves[start];
      if (end + 1 < s.size()) {
        ++moves[end + 1];
      }
    }
  }

  int accShift = 0;
  for (auto i = 0; i < s.size(); ++i) {
    accShift = (((accShift + moves[i]) % 26 + 26) % 26);
    s[i] = 'a' + static_cast<char>((s[i] - 'a' + accShift) % 26);
  }

  return s;
}

int main()
{
  // 2381. Shifting Letters II

  {
    std::string s = "abc";
    std::vector<std::vector<int>> shifts = {
      {0, 1, 0},
      {1, 2, 1},
      {0, 2, 1}
    };
    assert(shiftingLetters(s, shifts) == "ace");
  }

  {
    std::string s = "dztz";
    std::vector<std::vector<int>> shifts = {
      {0, 0, 0},
      {1, 1, 1}
    };
    assert(shiftingLetters(s, shifts) == "catz");
  }

  return 0;
}
