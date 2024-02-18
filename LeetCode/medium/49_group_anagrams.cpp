#include <algorithm>
#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
{
  std::vector<std::vector<std::string>> result;

  std::unordered_map<std::string, int> store;
  for (int i = 0; i < strs.size(); ++i) {
    std::string tmp = strs[i];
    std::sort(tmp.begin(), tmp.end());
    if (store.count(tmp) == 1) {
      result[store[tmp]].push_back(strs[i]);
    } else {
      store[tmp] = result.size();
      result.push_back({strs[i]});
    }
  }

  return result;
}

int main()
{
  // 49. Group Anagrams

  {
    std::vector<std::string> strs = {""};
    std::vector<std::vector<std::string>> expected = {{""}};
    assert(groupAnagrams(strs) == expected);
  }

  {
    std::vector<std::string> strs = {"a"};
    std::vector<std::vector<std::string>> expected = {{"a"}};
    assert(groupAnagrams(strs) == expected);
  }

  return 0;
}
