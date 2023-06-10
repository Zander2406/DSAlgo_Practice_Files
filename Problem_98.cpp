// Find a pair with given difference
#include <bits/stdc++.h>
using namespace std;

void findPair(vector<int> arr, int difference)
{
    pair<int, int> answer = {-1, -1};
    int n  = arr.size();
    unordered_set<int> cache;
    for (int i = 0; i < n; i++)
    {
        if (cache.find(arr[i] + difference) != cache.end())
        {
            answer.first = arr[i];
            answer.second = arr[i] + difference;
        }
        cache.insert(arr[i]);
    }

    std::cout << answer.first << " " << answer.second;
}

int main()
{
    vector<int> arr = {1, 8, 30, 40, 100};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n = -60;
    findPair(arr, n);

    return 0;
}