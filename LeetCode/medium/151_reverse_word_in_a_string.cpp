#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string reverseWords(std::string sentence)
{
  if (sentence.empty()) {
    return sentence;
  }

  std::stringstream ss {sentence};
  std::vector<std::string> words;
  std::string word;

  // Tokenize the sentence into words
  while (ss >> word) {
    words.push_back(word);
  }

  std::reverse(words.begin(), words.end());

  std::stringstream reversedSentence;
  for (int i = 0; i < words.size() - 1; ++i) {
    reversedSentence << words.at(i) << ' ';
  }
  reversedSentence << *words.rbegin();

  return reversedSentence.str();
}

std::string reverseWords_v2(std::string sentence)
{
  std::string reversed;
  std::string word;
  for (int i = sentence.size() - 1; i >= 0; --i) {
    if (std::isspace(sentence.at(i))) {
      if (!word.empty()) {
        reversed += word;
        word.clear();
      }
      if (!reversed.empty() && i > 0 && !std::isspace(sentence.at(i - 1))) {
        reversed += " ";
      }
    } else {
      word = sentence.at(i) + word;
    }
  }

  reversed += word;

  return reversed;
}

int main()
{
  // 151. Reverse Words in a String

  std::cout << (reverseWords_v2(" Hello World") == reverseWords("   Hello World")) << std::endl;
  std::cout << (reverseWords_v2("Coding is fun!") == reverseWords("Coding is fun!")) << std::endl;
  std::cout << (reverseWords_v2("Alice and Bob are friends") == reverseWords("Alice and Bob are friends")) << std::endl;

  return 0;
}
