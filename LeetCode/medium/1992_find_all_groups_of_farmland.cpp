#include <cassert>
#include <vector>

std::vector<int> getLandCoordinates(
  const std::vector<std::vector<int>>& land,
  std::size_t rowIdx,
  std::size_t colIdx,
  std::vector<std::vector<bool>>& visited
)
{
  if (rowIdx >= land.size() || colIdx >= land[0].size()) {
    return {};
  }

  if (visited[rowIdx][colIdx]) {
    return {};
  }

  visited[rowIdx][colIdx] = true;

  if (land[rowIdx][colIdx] == 0) {
    return {};
  }

  std::vector<int> coordinates =
    {static_cast<int>(rowIdx), static_cast<int>(colIdx), static_cast<int>(rowIdx), static_cast<int>(colIdx)};

  while (rowIdx < land.size() && land[rowIdx][colIdx] == 1) {
    visited[rowIdx][colIdx] = true;
    ++rowIdx;
  }
  --rowIdx;
  coordinates[2] = rowIdx;

  while (colIdx < land[0].size() && land[rowIdx][colIdx] == 1) {
    visited[rowIdx][colIdx] = true;
    ++colIdx;
  }
  --colIdx;
  coordinates[3] = colIdx;

  for (int i = coordinates[0]; i < coordinates[2]; ++i) {
    for (int j = coordinates[1] + 1; j <= coordinates[3]; ++j) {
      visited[i][j] = true;
    }
  }

  return coordinates;
}

std::vector<std::vector<int>> findFarmland(std::vector<std::vector<int>>& land)
{
  const int numRows = land.size();
  const int numCols = land[0].size();
  std::vector<std::vector<bool>> visited(numRows, std::vector<bool>(numCols, false));

  std::vector<std::vector<int>> farmlands;
  for (auto i = 0; i < numRows; ++i) {
    for (auto j = 0; j < numCols; ++j) {
      if (visited[i][j]) {
        continue;
      }

      auto coordinates = getLandCoordinates(land, i, j, visited);
      if (!coordinates.empty()) {
        farmlands.push_back(coordinates);
      }
    }
  }

  return farmlands;
}

int main()
{
  // 1992. Find All Groups of Farmland

  {
    std::vector<std::vector<int>> land = {
      {1, 0, 0},
      {0, 1, 1},
      {0, 1, 1}
    };
    std::vector<std::vector<int>> expectedCoordinates = {
      {0, 0, 0, 0},
      {1, 1, 2, 2}
    };
    auto result = findFarmland(land);
    assert(result == expectedCoordinates);
  }

  {
    std::vector<std::vector<int>> land = {
      {1, 1},
      {1, 1}
    };
    std::vector<std::vector<int>> expectedCoordinates = {
      {0, 0, 1, 1}
    };
    auto result = findFarmland(land);
    assert(result == expectedCoordinates);
  }

  {
    std::vector<std::vector<int>> land = {{0}};
    std::vector<std::vector<int>> expectedCoordinates = {};
    auto result = findFarmland(land);
    assert(result == expectedCoordinates);
  }

  return 0;
}
