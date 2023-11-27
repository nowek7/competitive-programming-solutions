#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int garbageCollection(std::vector<std::string>& garbage, std::vector<int>& travel)
{
  auto numGarbageType = [](const std::string& garbage, char type) {
    return std::count(garbage.begin(), garbage.end(), type);
  };

  int minutes = 0;
  int isCollected = false;
  for (auto gType: {'P', 'G', 'M'}) {
    for (int i = garbage.size() - 1; i >= 0; --i) {
      const int numGarbages = numGarbageType(garbage[i], gType);
      if (numGarbages > 0) {
        minutes += numGarbages;
        isCollected = true;
      }
      if (isCollected) {
        minutes += travel[i - 1];
      }
    }
    isCollected = false;
  }

  return minutes;
}

int main()
{
  // 2391. Minimum Amount of Time to Collect Garbage

  {
    std::vector<std::string> garbage = {"G", "P", "GP", "GG"};
    std::vector<int> travel = {2, 4, 3};
    std::cout << garbageCollection(garbage, travel) << '\n';
  }

  {
    std::vector<std::string> garbage = {"MMM", "PGM", "GP"};
    std::vector<int> travel = {3, 10};
    std::cout << garbageCollection(garbage, travel) << '\n';
  }

  return 0;
}
