int maxNumberOfBalloons(string text)
{
  std::unordered_map<char, int> frequency;
  for (char c: text) {
    if (c == 'b' || c == 'a' || c == 'l' || c == 'o' || 'n') {
      ++frequency[c];
    }
  }

  int maxNumber = std::min(frequency['b'], frequency['a']);
  maxNumber = std::min(maxNumber, frequency['n']);
  maxNumber = std::min(maxNumber, frequency['l'] / 2);
  maxNumber = std::min(maxNumber, frequency['o'] / 2);

  return maxNumber;
}

int main()
{
  // 1189. Maximum Number of Balloons

  {
    std::string text = "nlaebolko";
    // 1
  }

  {
    std::string text = "loonbalxballpoon";
    // 2
  }

  {
    std::string text = "leetcode";
    // 0
  }

  return 0;
}
