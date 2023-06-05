// Minimize the maximum difference between heights
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> testArray = {1, 5, 15, 10};
    int k = 3, n = testArray.size();

    // Naive Approach
    // sort(testArray.begin(), testArray.end());

    // int n = testArray.size();
    // int ans = testArray[n - 1] - testArray[0];
    // int tempmin = testArray[0], tempmax = testArray[n - 1];

    // for (int i = 1; i < n; i++)
    // {
    //     if (testArray[i] - k < 0)
    //         continue;
        
    //     tempmin = min(testArray[0] + k, testArray[i] - k);

    //     tempmax = max(testArray[i - 1] + k, testArray[n - 1] - k);

    //     ans = min(ans, tempmax - tempmin);
    // }

    // cout << ans;

    // Efficient Approach
    int minHeight = *min_element(testArray.begin(), testArray.end());
    int maxHeight = *max_element(testArray.begin(), testArray.end());

    int initialDifference = maxHeight - minHeight;

    int avgHeight = (minHeight + maxHeight) / 2;


    for (int i = 0; i < n; i++)
    {
        if (testArray[i] <= avgHeight)
            testArray[i] += k;
        else
            testArray[i] -= k;
    }


    int newMinHeight = *min_element(testArray.begin(), testArray.end());
    int newMaxHeight = *max_element(testArray.begin(), testArray.end());

    int newDifference = newMaxHeight - newMinHeight;

    std::cout << min(newDifference, initialDifference);

    return 0;
}