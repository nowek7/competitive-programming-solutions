#include <cassert>
#include <string>
#include <vector>

bool dfs(std::vector<std::vector<char>>& board, const std::string& word, std::size_t i, std::size_t j, std::size_t k)
{
  if (k == word.length()) {
    return true;
  }

  if (i < 0 || i >= board.size()) {
    return false;
  }

  if (j < 0 || j >= board[0].size()) {
    return false;
  }

  if (word[k] != board[i][j]) {
    return false;
  }

  char tmp = board[i][j];
  board[i][j] = '-';

  if (dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) || dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i, j - 1, k + 1)) {
    return true;
  }

  board[i][j] = tmp;
  return false;
}

bool exist(std::vector<std::vector<char>>& board, std::string word)
{
  const std::size_t numRows = board.size();
  const std::size_t numCols = board[0].size();
  for (std::size_t i = 0; i < numRows; ++i) {
    for (std::size_t j = 0; j < numCols; ++j) {
      if (board[i][j] != word[0]) {
        continue;
      }

      if (dfs(board, word, i, j, 0)) {
        return true;
      }
    }
  }

  return false;
}

int main()
{
  // 79. Word Search

  {
    std::vector<std::vector<char>> board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'}
    };
    std::string word = "ABCCED";
    assert(exist(board, word) == true);
  }

  {
    std::vector<std::vector<char>> board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'}
    };
    std::string word = "SEE";
    assert(exist(board, word) == true);
  }

  {
    std::vector<std::vector<char>> board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'}
    };

    std::string word = "ABCB";
    assert(exist(board, word) == false);
  }

  return 0;
}
