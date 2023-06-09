// Majority Element
#include <bits/stdc++.h>
using namespace std;

int majorityCandidate(vector<int> arr)
{
    int count = 1, idx = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[idx] == arr[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            idx = i;
            count = 1;
        }
    }

    return arr[idx];
}

int isMajor(vector<int> arr, int candidate)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == candidate)
            count++;
    }

    if (count > arr.size() / 2)
        return 1;
    return 0;
}

int main()
{
    vector<int> arr = { 1, 3, 3, 3, 2 };
    int major = majorityCandidate(arr);
    if (isMajor(arr, major))
        std::cout << "Major Element " << major;
    else
        std::cout << "No major element.";

    return 0;
}