#include <string>

#include <iostream>

int lengthOfLastWord(std::string s) 
{
    int count = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s.at(i) != ' ') {
            ++count;
        } else if (count > 0) {
            return count;
        }
    }
    return count;
}

int main()
{  
    // 58. Length of Last Word
    {
        std::string text = "Hello World";
        std::cout << lengthOfLastWord(text) << '\n';
    }

    {
        std::string text = "   fly me   to   the moon  ";
        std::cout << lengthOfLastWord(text) << '\n';
    }

    {
        std::string text = "luffy is still joyboy";
        std::cout << lengthOfLastWord(text) << '\n';
    }

    return 0;
}