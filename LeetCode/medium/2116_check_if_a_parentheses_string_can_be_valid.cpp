#include <cassert>
#include <stack>
#include <string>

bool canBeValid(std::string s, std::string locked)
{
  if (s.length() % 2 == 1) {
    return false;
  }

  std::stack<int> opens;
  std::stack<int> unlocks;
  for (auto i = 0; i < s.length(); ++i) {
    if (locked[i] == '0') {
      unlocks.push(i);
    } else if (s[i] == '(') {
      opens.push(i);
    } else if (s[i] == ')') {
      if (!opens.empty()) {
        opens.pop();
      } else if (!unlocks.empty()) {
        unlocks.pop();
      } else {
        return false;
      }
    }
  }

  while (!opens.empty() && !unlocks.empty() && opens.top() < unlocks.top()) {
    opens.pop();
    unlocks.pop();
  }

  if (!opens.empty()) {
    return false;
  }

  return true;
}

int main()
{
  // 2116. Check if a Parentheses String Can Be Valid

  {
    std::string s = "))()))";
    std::string locked = "010100";
    assert(canBeValid(s, locked) == true);
  }

  {
    std::string s = "()()";
    std::string locked = "0000";
    assert(canBeValid(s, locked) == true);
  }

  {
    std::string s = ")";
    std::string locked = "0";
    assert(canBeValid(s, locked) == false);
  }

  {
    std::string s = "(((())(((())";
    std::string locked = "111111010111";
    assert(canBeValid(s, locked) == true);
  }

  return 0;
}
