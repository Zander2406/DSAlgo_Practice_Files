// Find the largest sum of contiguous subarray
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> testArray = {34, 2, 45, 89, 2, 11, 45, 66};

    // This is also called Kadane's Algorithm
    int sum = 0, result = INT_MIN;

    for (int i = 0; i < testArray.size(); i++)
    {
        sum += testArray[i];
        result = max(result, sum);
        sum = max(sum, 0);
    }

    cout << "Largest Sum = " << result;

    return 0;
}