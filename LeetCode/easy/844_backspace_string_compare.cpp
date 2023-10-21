#include <cassert>
#include <stack>
#include <string>

std::stack<char> getStringAfterBackspaceModify(std::string& s)
{
  std::stack<char> pile;
  for (char c: s) {
    if (c == '#') {
      if (!pile.empty()) {
        pile.pop();
      }
    } else {
      pile.push(c);
    }
  }

  return pile;
}

bool backspaceCompare(std::string s, std::string t)
{
  std::stack<char> pileS = getStringAfterBackspaceModify(s);
  std::stack<char> pileT = getStringAfterBackspaceModify(t);

  return pileS == pileT;
}

int main()
{
  // 844. Backspace String Compare

  {
    std::string s = "ab#c";
    std::string t = "ad#c";
    assert(backspaceCompare(s, t) == true);
  }

  {
    std::string s = "ab##";
    std::string t = "c#d#";
    assert(backspaceCompare(s, t) == true);
  }

  {
    std::string s = "a#c";
    std::string t = "b";
    assert(backspaceCompare(s, t) == false);
  }

  return 0;
}
