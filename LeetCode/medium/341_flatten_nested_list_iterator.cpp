/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
private:
  int pos {0};
  std::vector<int> container {};

  void extractIntegers(std::vector<int>& numbers, std::vector<NestedInteger>& nestedList)
  {
    for (auto entry: nestedList) {
      if (entry.isInteger()) {
        numbers.push_back(entry.getInteger());
      } else {
        auto nested = entry.getList();
        extractIntegers(numbers, nested);
      }
    }
  }

public:
  NestedIterator(std::vector<NestedInteger>& nestedList)
  {
    extractIntegers(container, nestedList);
  }

  int next()
  {
    return container[pos++];
  }

  bool hasNext()
  {
    return pos < container.size();
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
