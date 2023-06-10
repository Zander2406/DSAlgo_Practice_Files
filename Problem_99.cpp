// Find four elements that add to a given sum
#include <bits/stdc++.h>
using namespace std;

map<int, pair<int, int>> twoSum(vector<int> arr)
{
    map<int, pair<int, int>> Map;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            Map[arr[i] + arr[j]].first = i;
            Map[arr[i] + arr[j]].second = j;
        }
    }
    return Map;
}

void fourSum(vector<int> arr, int sum, map<int, pair<int, int>> Map)
{
    int n = arr.size();
    vector<int> visited(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int curr_sum = arr[i] + arr[j];
            if (Map.find(sum - curr_sum) != Map.end())
            {
                pair<int, int> indexes = Map[sum - curr_sum];
                if (indexes.first != i && indexes.second != i && indexes.first != j && indexes.second != j
                && visited[indexes.first] == 0 && visited[indexes.second] == 0 && visited[i] == 0 && visited[j] == 0)
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[indexes.first] << " " << arr[indexes.second];
                    visited[i] = 1;
                    visited[j] = 1;
                    visited[indexes.second] = 1;
                    break;
                }
            }
        }
    }
}

int main()
{
    vector<int> arr = { 10, 20, 30, 40, 1, 2 };
    int X = 91;
    map<int, pair<int, int>> Map = twoSum(arr);
     
    fourSum(arr, X, Map);

    return 0;
}