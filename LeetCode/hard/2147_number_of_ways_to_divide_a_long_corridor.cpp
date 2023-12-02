#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int numberOfWays(std::string corridor)
{
  std::vector<int> seatsIdx;
  for (int i = 0; i < corridor.size(); ++i) {
    if (corridor[i] == 'S') {
      seatsIdx.push_back(i);
    }
  }

  if (seatsIdx.empty()) {
    return 0;
  }

  if (seatsIdx.size() % 2 == 1) {
    return 0;
  }

  if (seatsIdx.size() == 2) {
    return 1;
  }

  const int mod = 1e9 + 7;
  int result = 1;
  for (int i = 1; i < seatsIdx.size() - 1; i += 2) {
    long long diff = seatsIdx[i + 1] - seatsIdx[i];
    result = (result * diff) % mod;
  }

  return result;
}

int numberOfWays_v2(std::string corridor)
{
  const int mod = 1e9 + 7;

  long long result = 1;
  int numPlants = 0;
  int numSeats = 0;
  for (int i = 0; i < corridor.size(); ++i) {
    if (corridor[i] == 'S') {
      ++numSeats;
    } else {
      if (numSeats == 2) {
        ++numPlants;
      }
    }

    if (numSeats == 3) {
      result = (result * (numPlants + 1)) % mod;
      numSeats = 1;
      numPlants = 0;
    }
  }

  if (numSeats != 2) {
    return 0;
  }

  return result;
}

int main()
{
  // 2147. Number of Ways to Divide a Long Corridor

  {
    std::string s = "SSPPSPS";
    assert(numberOfWays(s) == 3);
  }

  {
    std::string s = "P";
    assert(numberOfWays(s) == 0);
  }

  {
    std::string s = "S";
    assert(numberOfWays(s) == 0);
  }

  {
    std::string s = "SSPPSP";
    assert(numberOfWays(s) == 0);
  }

  return 0;
}