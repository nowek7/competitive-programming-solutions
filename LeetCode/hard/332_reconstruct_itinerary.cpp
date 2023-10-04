#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets)
{
  std::unordered_map<std::string, std::vector<std::string>> flights;
  for (auto& t: tickets) {
    flights[t.front()].push_back(t.back());
  }

  for (auto& [_, entry]: flights) {
    std::sort(entry.begin(), entry.end());
  }

  std::vector<std::string> itinerary;
  std::function<void(std::string)> dfs;
  dfs = [&itinerary, &flights, &dfs](std::string airport) {
    std::vector<std::string>& destinations = flights[airport];
    while (!destinations.empty()) {
      std::string nextDestination = destinations.back();
      destinations.pop_back();
      dfs(nextDestination);
    }
    itinerary.push_back(airport);
  };

  dfs("JFK");
  std::reverse(itinerary.begin(), itinerary.end());

  return itinerary;
}

void printItinerary(std::vector<std::string> itinerary)
{
  for (int i = 0; i < itinerary.size() - 1; ++i) {
    std::cout << itinerary.at(i) << " -> ";
  }
  if (!itinerary.empty()) {
    std::cout << *itinerary.rbegin() << '\n';
  }
}

int main()
{
  {
    std::vector<std::vector<std::string>> tickets = {
      {"MUC", "LHR"},
      {"JFK", "MUC"},
      {"SFO", "SJC"},
      {"LHR", "SFO"}
    };
    const auto itinerary = findItinerary(tickets);
    printItinerary(itinerary);
  }
  std::cout << "-------------" << '\n';
  {
    std::vector<std::vector<std::string>> tickets = {
      {"JFK", "SFO"},
      {"JFK", "ATL"},
      {"SFO", "ATL"},
      {"ATL", "JFK"},
      {"ATL", "SFO"}
    };
    const auto itinerary = findItinerary(tickets);
    printItinerary(itinerary);
  }

  return 0;
}