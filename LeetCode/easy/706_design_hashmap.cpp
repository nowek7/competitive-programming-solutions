#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

class MyHashMap
{
private:
  constexpr static int SIZE = 37199;
  std::list<std::pair<int, int>> nodes[SIZE];

  int hash(int key)
  {
    return (2 * key + 97) % SIZE;
  }

  std::pair<int, int>* findByKey(int key)
  {
    const int idx = hash(key);
    auto it = std::find_if(nodes[idx].begin(), nodes[idx].end(), [&key](auto entry) {
      return entry.first == key;
    });
    if (it != nodes[idx].end()) {
      return &(*it);
    } else {
      return nullptr;
    }
  }

public:
  MyHashMap()
  {
  }

  void put(int key, int value)
  {
    std::pair<int, int>* entry = findByKey(key);
    if (entry) {
      entry->second = value;
    } else {
      nodes[hash(key)].push_back({key, value});
    }
  }

  int get(int key)
  {
    std::pair<int, int>* entry = findByKey(key);
    return entry ? entry->second : -1;
  }

  void remove(int key)
  {
    auto& node = nodes[hash(key)];
    auto pos = std::remove_if(node.begin(), node.end(), [&key](auto entry) {
      return entry.first == key;
    });
    node.erase(pos);
  }
};

int main()
{
  // 706. Design HashMap
  {
    MyHashMap* obj = new MyHashMap();

    obj->put(1000000, 1);
    {
      int value = obj->get(1000000);
      std::cout << value << '\n';
    }
    obj->put(0, 2);
    {
      int value = obj->get(0);
      std::cout << value << '\n';
    }

    delete obj;
  }

  return 0;
}