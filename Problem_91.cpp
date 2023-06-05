// Search an element in a sorted and rotated array
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int low, int high, int key)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        
        if (arr[low] < arr[mid])
        {
            if (key >= arr[low] && key <= arr[mid])
                return binarySearch(arr, low, mid - 1, key);
            return binarySearch(arr, mid + 1, high, key);
        }

        if (key >= arr[mid] && key <= arr[high])
            return binarySearch(arr, mid + 1, high, key);
        return binarySearch(arr, low, mid - 1, key);
    }
    return -1;
}

int main()
{
    vector<int> arr = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
    int key = 7;
    int ans = binarySearch(arr, 0, arr.size() - 1, key);
    if (ans == -1)
        std::cout << "Key not found";
    else
        std::cout << "Key found at index " << ans;

    return 0;
}