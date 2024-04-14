#include <algorithm>
#include <cassert>
#include <climits>
#include <vector>

std::vector<int> deckRevealedIncreasing(std::vector<int>& deck)
{
  std::vector<int> result(deck.size(), INT_MIN);

  std::sort(deck.begin(), deck.end());

  const int mod = static_cast<int>(deck.size());
  for (std::size_t i = 0; i < deck.size(); ++i) {
    auto idx = i * 2;
    while (idx >= mod) {
      idx = (idx % mod) * 2 + 1;
    }
    result[idx] = deck[i];
  }

  return result;
}

int main()
{
  // 950. Reveal Cards In Increasing Order

  {
    std::vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    std::vector<int> expected = {2, 13, 3, 11, 5, 17, 7};
    assert(deckRevealedIncreasing(deck) == expected);
  }

  {
    std::vector<int> deck = {1, 1000};
    std::vector<int> expected = {1, 1000};
    assert(deckRevealedIncreasing(deck) == expected);
  }

  return 0;
}