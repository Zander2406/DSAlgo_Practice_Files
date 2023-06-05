// Finding the kth minimum element in an array
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> test = {23, 45, 11, 99, 23, 78, 7, 1};
    int k = 4;

    // Brute Force
    // if (k > test.size())
    //     std::cout << "Out of range";
    
    // sort(test.begin(), test.end());
    // std::cout << test[k - 1];

    // Efficient Way
    map<int, int> freqTable;
    for (int i = 0; i < test.size(); i++)
    {
        freqTable[test[i]]++;
    }

    int target = 0;
    for (auto it = freqTable.begin(); it != freqTable.end(); it++)
    {
        target += it->second;
        if (target >= k)
        {
            std::cout << it->first;
            break;
        }
    }

    return 0;
}