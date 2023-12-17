#include <set>
#include <string>
#include <unordered_map>
#include <vector>

struct FoodElement
{
  std::string m_name;
  std::string m_cuisine;
  int m_rating {};

  FoodElement() = default;

  FoodElement(std::string name, std::string cuisine, int rating):
    m_name {name},
    m_cuisine {cuisine},
    m_rating {rating}
  {
  }

  bool operator<(const FoodElement& rhs) const
  {
    if (m_rating == rhs.m_rating) {
      return m_name < rhs.m_name;
    }
    return m_rating > rhs.m_rating;
  }
};

class FoodRatings
{
private:
  std::unordered_map<std::string, FoodElement> m_menu;
  std::unordered_map<std::string, std::set<FoodElement>> m_sortedFoodsPerCousine;

public:
  FoodRatings(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings)
  {
    for (int i = 0; i < foods.size(); ++i) {
      m_menu[foods[i]] = FoodElement(foods[i], cuisines[i], ratings[i]);
      m_sortedFoodsPerCousine[cuisines[i]].emplace(foods[i], cuisines[i], ratings[i]);
    }
  }

  void changeRating(std::string food, int newRating)
  {
    FoodElement& entry = m_menu[food];
    m_sortedFoodsPerCousine[entry.m_cuisine].erase(entry);
    entry.m_rating = newRating;
    m_sortedFoodsPerCousine[entry.m_cuisine].insert(entry);
  }

  std::string highestRated(std::string cuisine)
  {
    return m_sortedFoodsPerCousine[cuisine].begin()->m_name;
  }
};

int main()
{
  // 2353. Design a Food Rating System

  return 0;
}