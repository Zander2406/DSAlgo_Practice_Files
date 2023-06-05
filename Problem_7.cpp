// Cyclically rotate an array by one
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> testArray = {1, 2, 3, 4, 5, 6};

    // Brute Force
    // int extra = testArray[testArray.size() - 1];

    // for (int i = testArray.size() - 1; i > 0; i--)
    // {
    //     testArray[i] = testArray[i - 1];
    // }
    // testArray[0] = extra;

    // for (int i = 0; i < testArray.size(); i++)
    //     std::cout << testArray[i] << " ";

    // Efficient Approach
    int i = 0, j = testArray.size() - 1;

    while (i != j)
    {
        swap(testArray[i], testArray[j]);
        i++;
    }

    for (int i = 0; i < testArray.size(); i++)
        std::cout << testArray[i] << " ";

    
    return 0;
}