// Minimum characters to be added at front to make string palindrome
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "tcitkg";
    int n = str.length() - 1;
    int left = 0, right = n, count = 0;

    while (left < right)
    {
        // If we find common elements we go ahead and move both pointers towards each other
        if (str[left] == str[right])
        {
            left++;
            right--;
        }

        // Now since we know that we only need to add characters to the front we can go ahead and count the characters we need to add from the right side only
        if (str[left] != str[right])
        {
            count++;
            left = 0;
            right = n - count;
        }
    }

    std::cout << count << endl;

    return 0;
}