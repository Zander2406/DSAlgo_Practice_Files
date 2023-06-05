// Find duplicates in an array of N + 1 integers
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> testArray = {1, 3, 4, 2, 2};
    int n = testArray.size();

    // Brute Force
    // vector<int> countArray(n + 1, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     countArray[testArray[i]]++;
    // }

    // for (int i = 0; i < n + 1; i++)
    // {
    //     if (countArray[i] > 1)
    //     {
    //         std::cout << i;
    //         break;
    //     }
    // }

    // Efficient Approach
    int slow, fast;
    slow = testArray[0];
    fast = testArray[0];

    do
    {
        slow = testArray[slow];
        fast = testArray[testArray[fast]];
    }while (slow != fast);

    fast = testArray[0];

    while (slow != fast)
    {
        slow = testArray[slow];
        fast = testArray[fast];
    }

    std::cout << fast;

    return 0;
}