// Next Permutation
#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &array)
{
    int index1 = -1, index2 = -1;

    for (int i = array.size() - 2; i >= 0; i--)
    {
        if (array[i] < array[i + 1])
        {
            index1 = i;
            break;
        }
    }

    if (index1 == -1)
    {
        reverse(array.begin(), array.end());
    }
    else
    {
        for (int i = array.size() - 1; i >= 0; i--)
        {
            if (array[i] > array[index1])
            {
                index2 = i;
                break;
            }
        }
    }

    swap(array[index1], array[index2]);
    reverse(array.begin() + 1 + index1, array.end());

    return;
}

int main()
{
    vector<int> array = {1,2,3};
    // next_permutation(array.begin(), array.end());
    nextPermutation(array);

    for (int i = 0; i < array.size(); i++)
        cout << array[i];

    return 0;
}