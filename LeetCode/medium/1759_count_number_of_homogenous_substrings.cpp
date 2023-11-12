#include <iostream>
#include <string>
#include <unordered_map>

int countHomogenous(std::string s)
{
  const int mod = 1e9 + 7;
  auto sum = [&mod](long long n) {
    return static_cast<long long>((1 + n) * 0.5 * n) % mod;
  };

  int result = 0;
  long long counter = 1;
  for (int i = 1; i < s.length(); ++i) {
    if (s[i - 1] == s[i]) {
      counter++;
    } else {
      result = (result + (sum(counter) % mod);
      counter = 1;
    }
  }

  result = result + (sum(counter) % mod);

  return result;
}

int countHomogenous_v2(std::string s)
{
  const int mod = 1e9 + 7;

  int result = 1;
  int counter = 1;
  for (int i = 1; i < s.length(); ++i) {
    if (s[i - 1] == s[i]) {
      result += ++counter;
      result = result % mod;
    } else {
      counter = 1;
      result += counter;
    }
  }

  return result;
}

int main()
{
  // 1759. Count Number of Homogenous Substrings
  {
    std::string s {"abbcccaa"};
    std::cout << countHomogenous(s) << '\n';
  }

  {
    std::string s {"xy"};
    std::cout << countHomogenous(s) << '\n';
  }

  {
    std::string s {"zzzzz"};
    std::cout << countHomogenous(s) << '\n';
  }

  return 0;
}
