#include <cassert>
#include <string>

void generateHappyStrings(int n, int k, std::string& curr, int& index, std::string& result)
{
  if (curr.length() == n) {
    ++index;
    if (index == k) {
      result = curr;
    }
  } else {
    for (char c = 'a'; c <= 'c'; ++c) {
      if (curr.length() > 0 && c == curr.back()) {
        continue;
      }

      curr += c;
      generateHappyStrings(n, k, curr, index, result);
      if (!result.empty()) {
        return;
      }

      curr.pop_back();
    }
  }
}

std::string getHappyString(int n, int k)
{
  std::string result;
  std::string curr;
  int index = 0;

  generateHappyStrings(n, k, curr, index, result);

  return result;
}

int main()
{
  // 1415. The k-th Lexicographical String of All Happy Strings of Length n

  {
    int n = 1;
    int k = 3;
    assert(getHappyString(n, k) == "c");
  }

  {
    int n = 1;
    int k = 4;
    assert(getHappyString(n, k) == "");
  }

  {
    int n = 3;
    int k = 9;
    assert(getHappyString(n, k) == "cab");
  }

  return 0;
}
