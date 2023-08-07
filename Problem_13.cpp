// Kadane's Algorithm
#include <bits/stdc++.h>
using namespace std;

int largestSum(vector<int> array)
{
    int max_so_far = 0, answer = 0, n = array.size();
    
    for (int i = 0; i < n; i++)
    {
        max_so_far += array[i];
        answer = max(answer, max_so_far);
        if (max_so_far < 0)
            max_so_far = 0;
    }

    return answer;
}

int main()
{
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    int result = largestSum(arr);
    cout << result << endl;

    return 0;
}