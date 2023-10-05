#include <iostream>
#include <string>
#include <vector>

bool winnerOfGame(std::string colors)
{
  if (colors.length() < 3) {
    return false;
  }

  int aliceMoves = 0;
  int bobMoves = 0;
  for (int i = 1; i < colors.size() - 1; ++i) {
    if (colors[i] == 'A') {
      if (colors[i - 1] == 'A' && colors[i + 1] == 'A') {
        ++aliceMoves;
      }
    } else {
      if (colors[i - 1] == 'B' && colors[i + 1] == 'B') {
        ++bobMoves;
      }
    }
  }

  return aliceMoves > bobMoves;
}

int main()
{
  // 2038. Remove Colored Pieces if Both Neighbors are the Same Color
  {
    std::string s = "AAABABB";
    std::cout << (winnerOfGame(s) ? "true" : "false") << '\n';
  }

  {
    std::string s = "A";
    std::cout << (winnerOfGame(s) ? "true" : "false") << '\n';
  }

  {
    std::string s = "AA";
    std::cout << (winnerOfGame(s) ? "true" : "false") << '\n';
  }

  {
    std::string s = "ABBBBBBBAAA";
    std::cout << (winnerOfGame(s) ? "true" : "false") << '\n';
  }

  return 0;
}