#include <cassert>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::string destCity(std::vector<std::vector<std::string>>& paths)
{
  std::unordered_set<std::string> cities;
  for (auto& p: paths) {
    cities.insert(p[1]);
  }

  for (auto& p: paths) {
    cities.erase(p[0]);
  }

  return *cities.begin();
}

std::string destCity_v2(std::vector<std::vector<std::string>>& paths)
{
  if (paths.size() == 1) {
    return paths.front().at(1);
  }

  std::string dest;
  std::unordered_map<std::string, std::string> table;
  for (auto& p: paths) {
    table[p[0]] = p[1];
    dest = p[1];
    while (table.count(dest)) {
      dest = table[dest];
    }
  }

  return dest;
}

int main()
{
  // 1436. Destination City

  {
    std::vector<std::vector<std::string>> paths = {
      {  "London",  "New York"},
      {"New York",      "Lima"},
      {    "Lima", "Sao Paulo"}
    };

    assert(destCity(paths) == "Sao Paulo");
  }

  {
    std::vector<std::vector<std::string>> paths = {
      {"B", "C"},
      {"D", "B"},
      {"C", "A"}
    };
    assert(destCity_v2(paths) == "A");
  }

  return 0;
}
