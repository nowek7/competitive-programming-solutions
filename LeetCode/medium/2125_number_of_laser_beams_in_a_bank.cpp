#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

int numberOfBeams(std::vector<std::string>& bank)
{
  std::vector<int> numDevicesPerRow;
  long long prevNumDevices = 0;
  long long numBeams = 0;
  for (int i = 0; i < bank.size(); ++i) {
    const int numDevices = std::count_if(bank[i].begin(), bank[i].end(), [](char c) {
      return c == '1';
    });
    if (numDevices > 0) {
      numBeams += prevNumDevices * numDevices;
      prevNumDevices = numDevices;
    }
  }

  return numBeams;
}

int main()
{
  // 2125. Number of Laser Beams in a Bank

  {
    std::vector<std::string> bank = {"011001", "000000", "010100", "001000"};
    assert(numberOfBeams(bank) == 8);
  }

  {
    std::vector<std::string> bank = {"000", "111", "000"};
    assert(numberOfBeams(bank) == 0);
  }

  return 0;
}
