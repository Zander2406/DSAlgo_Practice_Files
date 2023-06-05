// Minimize the number of jumps to reach the end of an array
#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int> jumps, int n)
{
    if (n == 1)
        return 0;
    
    int result = INT_MAX;

    for (int i = n - 2; i >= 0; i--)
    {
        if (i + jumps[i] >= n - 1)
        {
            int sub_result = minJumps(jumps, i + 1);
            if (sub_result != INT_MAX)
                result = min(result, sub_result + 1);
        }
    }

    return result;
}

int EfficientMinJumps(vector<int> arr, int n)
{
    int *jumps = new int[n];

    if (n == 0 || arr[0] == 0)
        return INT_MAX;
    
    jumps[0] = 0;

    for (int i = 1; i < n; i++)
    {
        jumps[i] = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (i <= (j + arr[j]) && jumps[j] != INT_MAX)
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }

    return jumps[n - 1];
}

int OptimalMinJumps(vector<int> arr, int n)
{
    if (n <= 1)
        return 0;
    if (arr[0] == 0)
        return -1;
    
    // The maximum distance we can go from the first element
    int maxReach = arr[0];
    // The number of steps we have from the first element
    int steps = arr[0];
    // We only do one jump from here
    int jumps = 1;

    for (int i = 1; i < n; i++)
    {
        // If we have reached the end we just return the jumps we have taken until now
        if (i == n - 1)
            return jumps;
        
        // For every element we choose the max of the reach we have and the reach we get from our current index
        maxReach = max(maxReach, i + arr[i]);

        // We reduce the steps since we move to another element
        steps--;

        // If we have exhausted all our steps then we need to make another jump
        if (steps == 0)
        {
            // If we have exhausted our steps we need to jump again
            jumps++;
            // If the current index is more than our maximum reach then we return -1
            if (i >= maxReach)
                return -1;
            // If current index is within our reach we just update the steps we will have from here on
            steps = maxReach - i;
        }
    }
    return -1;
}

int main()
{
    vector<int> testArray = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = testArray.size();

    // Brute Force
    // int result = minJumps(testArray, n);
    
    // if (result == INT_MAX)
    //     result = -1;

    // std::cout << result;

    // Efficient Approach
    // int result = EfficientMinJumps(testArray, n);

    // if (result == INT_MAX)
    //     result = -1;

    // std::cout << result;

    // Optimal Approach
    int result = OptimalMinJumps(testArray, n);

    std::cout << result;

    return 0;
}