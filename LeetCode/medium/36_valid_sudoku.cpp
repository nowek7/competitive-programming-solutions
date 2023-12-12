#include <array>
#include <bitset>
#include <iostream>
#include <vector>

bool isValidSudoku(std::vector<std::vector<char>>& board)
{
  std::vector<std::array<bool, 9>> cells(9, {false});
  std::vector<std::array<bool, 9>> rows(9, {false});
  std::vector<std::array<bool, 9>> cols(9, {false});

  auto isValidCell = [&cells](int rowIdx, int colIdx, int value) {
    const int idx = (rowIdx / 3) * 3 + (colIdx / 3);
    if (cells[idx][value]) {
      return false;
    } else {
      cells[idx][value] = true;
      return true;
    }
  };

  auto isValidRow = [&rows](int idx, int value) {
    if (rows[idx][value]) {
      return false;
    } else {
      rows[idx][value] = true;
      return true;
    }
  };

  auto isValidCol = [&cols](int idx, int value) {
    if (cols[idx][value]) {
      return false;
    } else {
      cols[idx][value] = true;
      return true;
    }
  };

  for (int i = 0; i < board.size(); ++i) {
    const auto& rowBoard = board[i];
    for (int j = 0; j < rowBoard.size(); ++j) {
      if (rowBoard[j] == '.') {
        continue;
      }
      if (!isValidRow(i, rowBoard[j] - '1')) {
        return false;
      }
      if (!isValidCol(j, rowBoard[j] - '1')) {
        return false;
      }
      if (!isValidCell(i, j, rowBoard[j] - '1')) {
        return false;
      }
    }
  }

  return true;
}

bool isValidSudoku_v2(std::vector<std::vector<char>>& board)
{
  bool flag = true;
  std::bitset<9> row;
  for (int i = 0; i < 9; i++) {
    row = 0;
    for (int j = 0; j < 9; j++) {
      if (board[i][j] != '.') {
        flag &= !row[board[i][j]], row[board[i][j]] = true;
      }
    }
  }

  for (int i = 0; i < 9; i++) {
    row = 0;
    for (int j = 0; j < 9; j++) {
      if (board[j][i] != '.') {
        flag &= !row[board[j][i]], row[board[j][i]] = true;
      }
    }
  }

  for (auto x: {0, 3, 6}) {
    for (auto y: {0, 3, 6}) {
      row = 0;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (board[x + i][y + j] != '.') {
            flag &= !row[board[x + i][y + j]], row[board[x + i][y + j]] = true;
          }
        }
      }
    }
  }
  return flag;
}

int main()
{
  // 36. Valid Sudoku

  {
    std::vector<std::vector<char>> board = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    std::cout << isValidSudoku(board) << '\n';
  }

  {
    std::vector<std::vector<char>> board = {
      {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    std::cout << isValidSudoku_v2(board) << '\n';
  }

  return 0;
}
