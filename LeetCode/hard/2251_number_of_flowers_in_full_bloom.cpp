#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> fullBloomFlowers(std::vector<std::vector<int>>& flowers, std::vector<int>& people)
{
  std::sort(flowers.begin(), flowers.end(), [](const auto& lhs, const auto& rhs) {
    return lhs[0] < rhs[0];
  });

  std::vector<int> result(people.size(), 0);
  for (auto flower: flowers) {
    int& start = flower[0];
    int& end = flower[1];
    for (int i = 0; i < people.size(); ++i) {
      int& peopleIdx = people[i];
      if (peopleIdx >= start && peopleIdx <= end) {
        result[i]++;
      }
    }
  }

  return result;
}

std::vector<int> fullBloomFlowers_v2(std::vector<std::vector<int>>& flowers, std::vector<int>& people)
{
  std::vector<int> startingTimes(flowers.size());
  std::vector<int> endingTimes(flowers.size());

  for (int i = 0; i < flowers.size(); ++i) {
    startingTimes[i] = flowers[i][0];
    endingTimes[i] = flowers[i][1];
  }

  std::sort(startingTimes.begin(), startingTimes.end());
  std::sort(endingTimes.begin(), endingTimes.end());

  std::vector<int> result(people.size(), 0);
  for (int i = 0; i < people.size(); ++i) {
    auto start = std::upper_bound(startingTimes.begin(), startingTimes.end(), people[i]) - startingTimes.begin();
    auto end = std::lower_bound(endingTimes.begin(), endingTimes.end(), people[i]) - endingTimes.begin();
    std::cout << people[i] << " -> " << start << " | " << end << '\n';
    result[i] = start - end;
  }

  return result;
}

int main()
{
  // 2251. Number of Flowers in Full Bloom

  auto printResult = [](const std::vector<int>& result) {
    if (!result.empty()) {
      for (int i = 0; i < result.size() - 1; ++i) {
        std::cout << result[i] << '\n';
      }
      std::cout << result.back() << '\n';
    }
  };

  {
    std::vector<std::vector<int>> flowers = {
      {1,  6},
      {3,  7},
      {9, 12},
      {4, 13}
    };
    std::vector<int> people = {2, 3, 7, 11};
    auto result = fullBloomFlowers_v2(flowers, people);
    printResult(result);
  }
  std::cout << "---------------" << '\n';
  {
    std::vector<std::vector<int>> flowers = {
      {1, 10},
      {3,  3}
    };
    std::vector<int> people = {3, 3, 2};
    auto result = fullBloomFlowers_v2(flowers, people);
    printResult(result);
  }

  return 0;
}