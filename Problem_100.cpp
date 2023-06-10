// Find maximum possible stolen value from houses
#include <bits/stdc++.h>
using namespace std;

int maxLoot(vector<int> arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;

    int val1 = arr[0];
    if (n == 1)
        return val1;
    
    int val2 = max(arr[0], arr[1]);
    if (n == 2)
        return val2;
    
    int maxVal;
    for (int i = 2; i < n; i++)
    {
        maxVal = max(val1 + arr[i], val2);
        val1 = val2;
        val2 = maxVal;
    }

    return maxVal;

}

int main()
{
    vector<int> hval = { 6, 7, 1, 3, 8, 2, 4 };
    cout << "Maximum loot possible : " << maxLoot(hval);

    return 0;
}