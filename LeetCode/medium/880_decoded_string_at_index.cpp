#include <cctype>
#include <iostream>
#include <string>

std::string decodeAtIndex(std::string s, int k)
{
  int decodedSize = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (std::isdigit(s[i])) {
      decodedSize *= s[i] - '0';
    } else {
      ++decodedSize;
    }
  }

  for (int i = s.length() - 1; i >= 0; --i) {
    if (std::isdigit(s.at(i))) {
      decodedSize /= s[i] - '0';
      k %= decodedSize;
    } else {
      if (k == 0 || k == decodedSize) {
        return std::string(1, s[j])
      }
      --decodedSize;
    }
  }

  return "";
}

std::string decodeAtIndex_v2(std::string s, int k)
{
  // Not optimal - "brute force"
  std::string tape;
  for (char c: s) {
    if (std::isdigit(c)) {
      const auto digit = std::atoll(&c);
      if (digit * tape.length() > k) {
        k = k % tape.length();
        return std::string(1, tape[k > 0 ? k - 1 : 0]);
      }

      std::string prevTape = tape;
      for (auto i = 0; i < digit - 1; ++i) {
        tape += prevTape;
        if (tape.length() - 1 >= k) {
          return std::string(1, tape[k - 1]);
        }
      }
    } else {
      tape += c;
      if (tape.length() - 1 >= k) {
        return std::string(1, tape[k - 1]);
      }
    }
  }

  return std::string(1, tape[k - 1]);
}

int main()
{
  {
    std::cout << decodeAtIndex("leet2code3", 10) << '\n';
  }

  {
    std::cout << decodeAtIndex("ha22", 5) << '\n';
  }

  {
    std::cout << decodeAtIndex("a2345678999999999999999", 1) << '\n';
  }

  return 0;
}