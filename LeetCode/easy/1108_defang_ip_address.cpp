#include <algorithm>
#include <string>

#include <assert.h>
#include <iostream>

// Constraints: The given address is a valid IPv4 address.
std::string defangIPaddr(std::string address)
{
    std::string result;
    for (auto& c : address) {
        if (c == '.') {
            result += "[.]";
        } else {
            result += c;
        }
    }

    return result;
}

int main()
{
    // 1108. Defang IP Address
    {
        std::string address = "1.1.1.1";
        std::cout << defangIPaddr(address) << '\n';
        assert("1[.]1[.]1[.]1" == defangIPaddr(address));
    }

    {
        std::string address = "255.255.255.255";
        assert("255[.]255[.]255[.]255" == defangIPaddr(address));
    }

    return 0;
}