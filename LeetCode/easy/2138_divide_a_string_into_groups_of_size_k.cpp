#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> divideString(std::string s, int k, char fill)
{
  std::vector<std::string> result;

  int i = 0;
  while (i < s.size() - (s.size() % k)) {
    result.push_back(s.substr(i, k));
    i += k;
  }
  if (i < s.size()) {
    std::string last = s.substr(i, s.size() - i);
    for (int j = 0; j < k - (s.size() % k); ++j) {
      last += fill;
    }
    result.push_back(last);
  }

  return result;
}

std::vector<std::string> divideString_v2(std::string s, int k, char fill)
{
  std::vector<std::string> res((s.size() + k - 1) / k, std::string(k, fill));
  for (int i = 0; i < s.size(); ++i) {
    res[i / k][i % k] = s[i];
  }
  return res;
}

int main()
{
  // 2138. Divide a String Into Groups of Size k
  {
    auto result = divideString("abcdefghi", 3, 'x');
    for (auto entry: result) {
      std::cout << entry << '\n';
    }
  }
  return 0;
}
