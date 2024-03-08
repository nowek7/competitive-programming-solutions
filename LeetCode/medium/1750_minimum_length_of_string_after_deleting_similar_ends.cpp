#include <cassert>
#include <string>

int minimumLength(std::string s)
{
  int left = 0;
  int right = s.length() - 1;
  while (left < right && s[left] == s[right]) {
    int c = s[left];

    while (left <= right && s[left] == c) {
      ++left;
    }

    while (right >= left && s[right] == c) {
      --right;
    }
  }

  return right - left + 1;
}

int main()
{
  // 1750. Minimum Length of String After Deleting Similar Ends

  {
    std::string s = "ca";
    assert(minimumLength(s) == 2);
  }

  {
    std::string s = "cabaabac";
    assert(minimumLength(s) == 0);
  }

  {
    std::string s = "aabccabba";
    assert(minimumLength(s) == 3);
  }

  return 0;
}