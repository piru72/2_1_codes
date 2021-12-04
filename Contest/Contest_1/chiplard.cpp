// given n number of string find out the vowels in each string


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
int main()
{
    int n;
    std::cin >> n;
    std::vector<std::string> str(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> str[i];
    }
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < str[i].length(); j++)
        {
            if (std::tolower(str[i][j]) == 'a' || std::tolower(str[i][j]) == 'e' || std::tolower(str[i][j]) == 'i' || std::tolower(str[i][j]) == 'o' || std::tolower(str[i][j]) == 'u')
            {
                count++;
            }
        }
        std::cout << count << std::endl;
    }
    return 0;
}