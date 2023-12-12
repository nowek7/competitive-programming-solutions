#include <cassert>
#include <vector>

int knightDialer(int n)
{
  const int mod = 1e9 + 7;
  std::vector<long long> pos(10, 1);
  std::vector<long long> nextPos(10, 0);
  for (int i = 2; i <= n; ++i) {
    nextPos[0] = (pos[4] + pos[6]) % mod;
    nextPos[1] = (pos[6] + pos[8]) % mod;
    nextPos[2] = (pos[7] + pos[9]) % mod;
    nextPos[3] = (pos[4] + pos[8]) % mod;
    nextPos[4] = (pos[0] + pos[3] + pos[9]) % mod;

    nextPos[6] = (pos[0] + pos[1] + pos[7]) % mod;
    nextPos[7] = (pos[2] + pos[6]) % mod;
    nextPos[8] = (pos[1] + pos[3]) % mod;
    nextPos[9] = (pos[2] + pos[4]) % mod;

    for (int j = 0; j < 10; ++j) {
      pos[j] = nextPos[j];
    }
  }

  int result = 0;
  for (int i = 0; i < 10; ++i) {
    result = (result + pos[i]) % mod;
  }
  return result;
}

int main()
{
  // 935. Knight Dialer

  {
    assert(knightDialer(1) == 10);
  }

  {
    assert(knightDialer(2) == 20);
  }

  {
    assert(knightDialer(3131) == 136006598);
  }

  return 0;
}
