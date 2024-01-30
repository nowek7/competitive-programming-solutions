#include <random>
#include <unordered_map>
#include <vector>

class RandomizedSet
{
private:
  std::unordered_map<int, int> m_storage;
  std::vector<int> m_insertedNumbers;

public:
  RandomizedSet()
  {
  }

  bool insert(int val)
  {
    if (m_storage.count(val)) {
      return false;
    }

    m_storage[val] = m_insertedNumbers.size();
    m_insertedNumbers.emplace_back(val);

    return true;
  }

  bool remove(int val)
  {
    if (!m_storage.count(val)) {
      return false;
    }

    int pos = m_storage[val];
    m_storage[m_insertedNumbers.back()] = m_storage[val];
    m_insertedNumbers[pos] = m_insertedNumbers.back();

    m_insertedNumbers.pop_back();
    m_storage.erase(val);
    return true;
  }

  int getRandom()
  {
    int idx = std::rand() % m_insertedNumbers.size();

    return m_insertedNumbers[idx];
  }
};

int main()
{
  // 380. Insert Delete GetRandom O(1)

  /**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

  return 0;
}
