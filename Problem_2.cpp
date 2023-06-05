// Finding max and min in an array
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> test = {34, 65, 23, 5, 88, 9, 23, 545};

    // Brute Force
    int minimumElement = test[0];
    int maximumElement = test[0];

    for (int i = 0; i < test.size(); i++)
    {
        if (test[i] < minimumElement)
            minimumElement = test[i];
        if (test[i] > maximumElement)
            maximumElement = test[i];
    }

    cout << "Max = " << maximumElement << " Min = " << minimumElement;

    return 0;
}