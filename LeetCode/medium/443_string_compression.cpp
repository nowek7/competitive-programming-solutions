#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int compress(std::vector<char>& chars)
{
  std::vector<char> result;

  int numChar = 1;
  for (int i = 1; i < chars.size(); i++) {
    if (chars[i - 1] == chars[i]) {
      ++numChar;
    } else {
      result.push_back(chars[i - 1]);
      if (numChar > 1) {
        std::string s;
        while (numChar > 0) {
          s += ('0' + (numChar % 10));
          numChar /= 10;
        }
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
          result.push_back(*it);
        }
        numChar = 1;
      }
    }
  }

  result.push_back(chars.back());
  if (numChar > 1) {
    std::string s;
    while (numChar > 0) {
      s += ('0' + (numChar % 10));
      numChar /= 10;
    }
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
      result.push_back(*it);
    }
  }
  chars = result;
  return chars.size();
}

int compress_v2(std::vector<char>& chars)
{
  int i = 0;
  for (int j = 1, count = 1; j <= chars.size(); ++j, ++count) {
    if (j == chars.size() || chars[j] != chars[j - 1]) {
      chars[i] = chars[j - 1];
      ++i;
      if (count >= 2) {
        for (char digit: std::to_string(count)) {
          chars[i] = digit;
          ++i;
        }
      }
      count = 0;
    }
  }

  return i;
}

void printChars(const std::vector<char>& chars)
{
  if (!chars.empty()) {
    for (int i = 0; i < chars.size() - 1; ++i) {
      std::cout << chars[i];
    }
    std::cout << chars.back() << '\n';
  }
}

int main()
{
  // 443. String Compression

  {
    std::vector<char> chars {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    std::cout << "Length -> " << compress_v2(chars) << '\n';
    printChars(chars);
  }

  {
    std::vector<char> chars {'a'};
    std::cout << "Length -> " << compress(chars) << '\n';
    printChars(chars);
  }

  {
    std::vector<char> chars {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'}; // ab12
    std::cout << "Length -> " << compress(chars) << '\n';
    printChars(chars);
  }

  {
    std::vector<char> chars {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    std::cout << "Length -> " << compress(chars) << '\n';
    printChars(chars);
  }

  {
    std::vector<char> chars {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                             'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                             'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                             'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                             'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                             'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
    std::cout << "Length -> " << compress(chars) << '\n';
    printChars(chars);
  }

  return 0;
}
