#include <cassert>
#include <queue>
#include <vector>

std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>>& isWater)
{
  const int m = isWater.size();
  const int n = isWater[0].size();

  std::vector<std::vector<int>> cells(m, std::vector<int>(n, -1));
  std::queue<std::pair<int, int>> waterCellLine;
  for (auto i = 0; i < m; ++i) {
    for (auto j = 0; j < n; ++j) {
      if (isWater[i][j] == 1) {
        cells[i][j] = 0;
        waterCellLine.push({i, j});
      }
    }
  }

  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};

  int cellHeight = 1;
  while (!waterCellLine.empty()) {
    int layerSize = waterCellLine.size();
    for (auto i = 0; i < layerSize; ++i) {
      auto cell = waterCellLine.front();
      waterCellLine.pop();

      for (auto j = 0; j < 4; ++j) {
        std::pair<int, int> neighbourCell = {cell.first + dx[j], cell.second + dy[j]};

        if (neighbourCell.first >= 0 && neighbourCell.first < m && neighbourCell.second >= 0
            && neighbourCell.second < n) {
          if (cells.at(neighbourCell.first).at(neighbourCell.second) == -1) {
            cells[neighbourCell.first][neighbourCell.second] = cellHeight;
            waterCellLine.push(neighbourCell);
          }
        }
      }
    }
    ++cellHeight;
  }

  return cells;
}

int main()
{
  // 1765. Map of Highest Peak

  {
    std::vector<std::vector<int>> isWater = {
      {0, 1},
      {0, 0}
    };
    std::vector<std::vector<int>> result = highestPeak(isWater);
    std::vector<std::vector<int>> expected = {
      {1, 0},
      {2, 1},
    };
    assert(expected == result);
  }

  {
    std::vector<std::vector<int>> isWater = {
      {0, 0, 1},
      {1, 0, 0},
      {0, 0, 0}
    };
    std::vector<std::vector<int>> expected = {
      {1, 1, 0},
      {0, 1, 1},
      {1, 2, 2}
    };
    std::vector<std::vector<int>> result = highestPeak(isWater);
    assert(expected == result);
  }

  return 0;
}
