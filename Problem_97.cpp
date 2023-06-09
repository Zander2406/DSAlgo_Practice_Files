// Searching in an array where adjacent elements differ by at most k
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> arr, int target, int difference)
{
    int i = 0;
    while (i < arr.size())
    {
        if (arr[i] == target)
            return i;
        i += max (1, abs(arr[i] - target) / difference);
    }
    return -1;
}

int main()
{
    vector<int> arr = { 20, 40, 50, 70, 70, 60 };
    int index = search(arr, 60, 20);
    if (index == -1)
        std::cout << "Element not found";
    else
        std::cout << "Element found at " << index;

    return 0;
}