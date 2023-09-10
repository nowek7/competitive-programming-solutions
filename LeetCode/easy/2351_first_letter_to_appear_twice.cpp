#include <string>
#include <set>

#include <iostream>

char repeatedCharacter(std::string s)
{
    std::set<char> alphabet = { s.front() };
    int idx = 1;
    while (idx < s.length() && alphabet.count(s.at(idx)) == 0) {
        alphabet.insert(s.at(idx));
        ++idx;
    }

    return s.at(idx);
}

int main()
{
    // 2351. First Letter to Appear Twice
    {
        std::string s = "abcdd";
        std::cout << s << " -> " << repeatedCharacter(s) << '\n';
    }

    {
        std::string s = "abccbaacz";
        std::cout << s << " -> " << repeatedCharacter(s) << '\n';
    }

    {
        std::string s = "abcdefa";
        std::cout << s << " -> " << repeatedCharacter(s) << '\n';
    }
}