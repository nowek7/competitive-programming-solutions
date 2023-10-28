#include <cassert>
#include <unordered_map>

int countVowelPermutation(int n)
{
  const int mod = 1e9 + 7;

  std::unordered_map<char, long> dict = {
    {'a', 1},
    {'e', 1},
    {'i', 1},
    {'o', 1},
    {'u', 1}
  };
  for (int i = 1; i < n; ++i) {
    long nextA = dict['e'] % mod;
    long nextE = (dict['a'] + dict['i']) % mod;
    long nextI = (dict['a'] + dict['e'] + dict['o'] + dict['u']) % mod;
    long nextO = (dict['i'] + dict['u']) % mod;
    long nextU = (dict['a']) % mod;

    dict['a'] = nextA;
    dict['e'] = nextE;
    dict['i'] = nextI;
    dict['o'] = nextO;
    dict['u'] = nextU;
  }

  return static_cast<int>((dict['a'] + dict['e'] + dict['i'] + dict['o'] + dict['u']) % mod);
}

int main()
{
  // 1220. Count Vowels Permutation

  assert(countVowelPermutation(1) == 5);
  assert(countVowelPermutation(2) == 10);
  assert(countVowelPermutation(5) == 68);

  return 0;
}
