#include <stack>
#include <string>

#include <iostream>

bool isValid(std::string s)
{
    std::stack<char> container;

    for (auto c : s) {
        if (c == ')' || c == ']' || c == '}') {
            if (container.empty()) {
                return false;
            }

            if (std::abs(c - container.top()) <= 2) {
                container.pop();
            } else {
                return false;
            }
        } else {
            container.push(c);
        }
    }

    std::cout << container.size() << '\n';

    return container.empty();
}

int main()
{
    // 20. Valid Parentheses
    {
        std::string s = "()";
        std::cout << std::boolalpha << isValid(s) << '\n';
    }

    {
        std::string s = "()[]{}";
        std::cout << std::boolalpha << isValid(s) << '\n';
    }

    {
        std::string s = "(]";
        std::cout << std::boolalpha << isValid(s) << '\n';
    }

    {
        std::string s = "]()";
        std::cout << std::boolalpha << isValid(s) << '\n';
    }

    {
        std::string s = "[]{(]}([({})])";
        std::cout << std::boolalpha << isValid(s) << '\n';
    }

    {
        std::string s = "(])";
        std::cout << std::boolalpha << isValid(s) << '\n';
    }


    return 0;
}