// Find a Fixed Point (Value equal to index) in a given array
#include <bits/stdc++.h>
using namespace std;

int findFixedPoint(vector<int> arr, int start, int end)
{
    if (end >= start)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == mid)
            return mid;
        int result = -1;
        if (mid - 1 >= arr[start])
            result = findFixedPoint(arr, start, mid - 1);
        if (result != -1)
            return result;
        if (mid + 1 <= arr[end])
            return findFixedPoint(arr, mid + 1, end);
    }
    return -1;
}

int main()
{
    vector<int> arr = { -10, -1, 0, 3, 10, 11, 30, 50, 100 };
    cout << "Fixed Point is " << findFixedPoint(arr, 0, arr.size() - 1);

    return 0;
}