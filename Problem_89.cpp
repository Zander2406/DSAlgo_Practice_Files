// Find first and last occurence of an element in an array
#include <bits/stdc++.h>
using namespace std;

int findFirstAndLast(vector<int> arr, int x, bool isFirst)
{
    int low = 0, high = arr.size() - 1, result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (x < arr[mid])
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            result = mid;
            if (isFirst)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }

    return result;
}

int main()
{
    vector<int> arr = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
    int x = 8;
    int firstOccurence = -1, lastOccurence = -1;
    firstOccurence = findFirstAndLast(arr, x, true);
    if (firstOccurence != -1)
        lastOccurence = findFirstAndLast(arr, x, false);

    cout << firstOccurence << " " << lastOccurence;

    return 0;
}