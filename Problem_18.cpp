// Count pairs with given sum
#include <bits/stdc++.h>
using namespace std;

int getPairsCount(vector<int> nums, int target)
{
    int n = nums.size(), count = 0;
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        if (m.find(target - nums[i]) != m.end())
        {
            count += m[target - nums[i]];
        }
        m[nums[i]]++;
    }

    return count;
}


int main()
{
    vector<int> arr = {1, 5, 7, -1};
    int K = 6;
    cout << "Count of pairs is " << getPairsCount(arr, K);

    return 0;
}