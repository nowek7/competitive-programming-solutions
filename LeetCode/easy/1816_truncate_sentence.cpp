#include <iostream>
#include <string>

std::string truncateSentence(std::string s, int k)
{
  std::string result;

  int pos = 0;
  int prevPos = 0;
  while ((pos = s.find_first_of(' ', prevPos)) != std::string::npos)
  {
    if (pos > prevPos)
    {
      result += s.substr(prevPos, pos - prevPos);
      if (--k == 0)
      {
        return result;
      }
      else
      {
        result += " ";
      }
    }

    prevPos = pos + 1;
  }

  if (prevPos < s.length())
  {
    result += s.substr(prevPos, std::string::npos);
  }

  return result;
}

int main()
{
  // 1816. Truncate Sentence
  {
    std::string text = "Hello how are you Contestant";
    std::cout << truncateSentence(text, 5) << '\n';
  }

  return 0;
}