#include <cassert>
#include <cmath>
#include <string>

int maxDepth(std::string s)
{
  int depth = 0;
  int counter = 0;

  for (auto c: s) {
    if (c == '(') {
      ++counter;
    } else if (c == ')') {
      depth = std::max(depth, counter);
      --counter;
    }
  }

  return depth;
}

int main()
{
  // 1614. Maximum Nesting Depth of the Parentheses

  {
    std::string s = "(1+(2*3)+((8)/4))+1";
    assert(maxDepth(s) == 3);
  }

  {
    std::string s = "(1)+((2))+(((3)))";
    assert(maxDepth(s) == 3);
  }

  return 0;
}
