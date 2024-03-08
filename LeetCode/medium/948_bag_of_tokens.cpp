#include <algorithm>
#include <cassert>
#include <vector>

int bagOfTokensScore(std::vector<int>& tokens, int power)
{
  std::sort(tokens.begin(), tokens.end());

  int score = 0;
  int left = 0;
  int right = tokens.size() - 1;
  while (left <= right) {
    if (power >= tokens[left]) {
      power -= tokens[left];
      ++score;
      ++left;
    } else if (score > 0 && left < right) {
      power += tokens[right];
      --score;
      --right;
    } else {
      return score;
    }
  }

  return score;
}

int main()
{
  // 948. Bag of Tokens

  {
    std::vector<int> tokens = {100};
    int power = 50;
    assert(bagOfTokensScore(tokens, power) == 0);
  }

  {
    std::vector<int> tokens = {200, 100};
    int power = 150;
    assert(bagOfTokensScore(tokens, power) == 1);
  }

  {
    std::vector<int> tokens = {100, 200, 300, 400};
    int power = 200;
    assert(bagOfTokensScore(tokens, power) == 2);
  }

  return 0;
}