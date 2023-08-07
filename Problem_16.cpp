// Count Inversions
#include <bits/stdc++.h>
using namespace std;

int inversionCount(vector<int> array)
{
    int n = array.size(), inv_count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+ 1; j < n; j++)
        {
            if (array[i] > array[j])
                inv_count++;
        }
    }

    return inv_count;
}

int merge(int array[], int temp[], int left, int mid, int right)
{
    int i = left, j = mid, k = left, inv_count = 0;
    while ((i <= mid - 1) && (j <= right))
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
        {
            temp[k++] = array[j++];
            inv_count += mid - i;
        }
    }

    while (i <= mid - 1)
        temp[k++] = array[i++];
    
    while (j <= right)
        temp[k++] = array[j++];
    
    for (i = left; i <= right; i++)
        array[i] = temp[i];
    
    return inv_count;
}

int mergeSort(int array[], int temp_array[], int left, int right)
{
    int inv_count = 0, mid;
    if (right > left)
    {
        mid = left + (right - left) / 2;
        inv_count += mergeSort(array, temp_array, left, mid);
        inv_count += mergeSort(array, temp_array, mid + 1, right);
        inv_count += merge(array, temp_array, left, mid + 1, right);
    }

    return inv_count;
}


int main()
{
    int array[] = {1, 20, 6, 4, 5};
    int n = sizeof(array) / sizeof(array[0]);
    int temp_array[n];
    int answer = mergeSort(array, temp_array, 0, n - 1);
    // int answer = mergeSort(array, n);
    cout << answer;

    return 0;
}