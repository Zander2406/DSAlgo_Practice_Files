// Reversing an array code
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> test = {1, 2, 3, 4, 5, 6};


    // Brute Force method
    // int rev[6];
    // int j = 5;
    // for (int i = 0; i < 6; i++)
    // {
    //     rev[j] = test[i];
    //     j--;
    // }

    // for (int i = 0; i < 6; i++)
    // {
    //     cout << rev[i] << " ";
    // }


    // Efficient Approach
    int start = 0, end = test.size() - 1;
    while (start < end)
    {
        swap(test[start], test[end]);
        start++;
        end--;
    }

    for (int i = 0; i < test.size(); i++)
    {
        std::cout << test[i] << " ";
    }


    return 0;
}