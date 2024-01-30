#include <cassert>
#include <vector>

std::vector<double> convertTemperature(double celsius)
{
  return {static_cast<double>(celsius + 273.15), static_cast<double>(celsius * 1.80 + 32.00)};
}

int main()
{
  // 2469. Convert the Temperature

  {
    double celsius = 36.50;
    auto result = convertTemperature(celsius);
    auto expected = std::vector<double> {309.65000, 97.70000};
    assert(result == expected);
  }

  {
    double celsius = 122.11;
    auto result = convertTemperature(celsius);
    auto expected = std::vector<double> {395.26000, 251.79800};
    assert(result == expected);
  }

  return 0;
}
