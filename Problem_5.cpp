// Move all negative elements to one side of an array
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> test = {-1, 4, 2, 8, -3, -43, 32, 12, -5, -89};

    // Brute Force
    // sort(test.begin(), test.end());

    // Efficient approach
    int left = 0, right = test.size() - 1;
    while (left <= right)
    {
        if (test[left] < 0 && test[right] < 0)
            left++;
        if (test[left] > 0 && test[right] < 0)
            swap(test[left++], test[right++]);
        if (test[left] > 0 && test[right] > 0)
            right--;
        else
            left++, right--;
    }

    for (int i = 0; i < test.size(); i++)
        std::cout << test[i] << " ";

    return 0;
}