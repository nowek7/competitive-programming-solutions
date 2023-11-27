#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string findDifferentBinaryString(std::vector<std::string>& nums)
{
  auto nextBinary = [](std::string& binary) {
    auto lastFalse = std::find(binary.rbegin(), binary.rend(), '0');
    auto lastToFlip = (lastFalse == binary.rend()) ? binary.rend() : std::next(lastFalse);
    std::for_each(binary.rbegin(), lastToFlip, [](char& bit) {
      bit = bit == '0' ? '1' : '0';
    });
  };

  const int lengthBinary = nums.front().size();

  std::string missingBinary = std::string(lengthBinary, '0');
  auto it = std::find(nums.begin(), nums.end(), missingBinary);
  while (it != nums.end()) {
    nextBinary(missingBinary);
    it = std::find(nums.begin(), nums.end(), missingBinary);
  }

  return missingBinary;
}

int main()
{
  // 1980. Find Unique Binary String

  {
    std::vector<std::string> binaries = {"01", "10"};
    std::cout << findDifferentBinaryString(binaries) << '\n';
  }

  {
    std::vector<std::string> binaries = {"00", "10"};
    std::cout << findDifferentBinaryString(binaries) << '\n';
  }

  {
    std::vector<std::string> binaries = {"111", "011", "001"};
    std::cout << findDifferentBinaryString(binaries) << '\n';
  }

  return 0;
}