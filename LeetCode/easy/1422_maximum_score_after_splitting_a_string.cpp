#include <cassert>
#include <climits>
#include <string>
#include <vector>

int maxScore(std::string s)
{
  std::vector<int> zeros(s.length() - 1, 0);
  std::vector<int> ones(s.length() - 1, 0);
  std::pair<int, int> counter {0, 0};
  for (int i = 0, j = s.length() - 1; i < s.length() - 1 && j > 0; ++i, --j) {
    if (s[i] == '0') {
      zeros[i] = ++counter.first;
    } else {
      zeros[i] = counter.first;
    }
    if (s[j] == '1') {
      ones[j - 1] = ++counter.second;
    } else {
      ones[j - 1] = counter.second;
    }
  }

  int score = INT_MIN;
  for (int i = 0; i < s.length() - 1; ++i) {
    score = std::max(score, zeros[i] + ones[i]);
  }

  return score;
}

int main()
{
  // 1422. Maximum Score After Splitting a String

  {
    std::string s = "011101";
    assert(maxScore(s) == 5);
  }

  {
    std::string s = "00111";
    assert(maxScore(s) == 5);
  }

  {
    std::string s = "1111";
    assert(maxScore(s) == 3);
  }

  return 0;
}
