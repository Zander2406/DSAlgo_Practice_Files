// Merge 2 sorted array without using extra space
#include <bits/stdc++.h>
using namespace std;

void sortArrays(vector<int> &array1, vector<int> &array2, int n, int m)
{
    int i = 0, j = 0, k = n - 1;

    while (i <= k && j < m)
    {
        if (array1[i] < array2[j])
            i++;
        else
            swap(array2[j++], array1[k--]);
    }

    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());
}

int main()
{
    vector<int> array1 = {1, 5, 9, 10, 15, 20};
    vector<int> array2 = {2, 3, 8, 13};
    int n = array1.size();
    int m = array2.size();
    sortArrays(array1, array2, n, m);
    for (int i = 0; i < n; i++)
        cout << array1[i] << " ";
    cout << endl;
    for (int i = 0; i < m; i++)
        cout << array2[i] << " ";

    return 0;
}