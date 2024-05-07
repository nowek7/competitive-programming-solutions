#include <array>
#include <cassert>
#include <queue>
#include <string>
#include <vector>

int openLock(std::vector<std::string>& deadends, std::string target)
{
  std::array<bool, 10'000> attempts {false};
  for (auto& entry: deadends) {
    attempts[std::stoi(entry)] = true;
  }

  if (attempts[0]) {
    return -1;
  }

  std::queue<std::pair<int, std::string>> line;
  line.emplace(0, "0000");
  attempts[0] = true;

  while (!line.empty()) {
    auto [turn, strValue] = line.front();
    line.pop();

    if (strValue == target) {
      return turn;
    }

    for (auto slotIdx = 0; slotIdx < 4; ++slotIdx) {
      for (auto i = -1; i <= 1; i += 2) {
        std::string strNextValue = strValue;
        char& slot = strNextValue[slotIdx];
        slot = (slot - '0' + i + 10) % 10 + '0';
        int value = std::stoi(strNextValue);
        if (!attempts[value]) {
          line.emplace(turn + 1, strNextValue);
          attempts[value] = true;
        }
      }
    }
  }

  return -1;
}

int main()
{
  // 752. Open the Lock

  {
    std::vector<std::string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    assert(openLock(deadends, "0202") == 6);
  }

  {
    std::vector<std::string> deadends = {"8888"};
    assert(openLock(deadends, "0009") == 1);
  }

  {
    std::vector<std::string> deadends = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    assert(openLock(deadends, "8888") == -1);
  }

  return 0;
}
