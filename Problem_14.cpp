// Merge Intervals
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    vector<vector<int>> ans;
    int n = intervals.size();
    if (n == 0)
        return ans;
    sort(intervals.begin(), intervals.end());
        
    int start = intervals[0][0];
    int end = intervals[0][1];
        
    for (int i = 1; i < n; i++)
    {
        if (end >= intervals[i][0])
        {
            end = max(end, intervals[i][1]);
        }
        else
        {
            ans.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }
        
    ans.push_back({start, end});
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> answer = merge(intervals);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i][0] << " " << answer[i][1] << endl;
    }

    return 0;
}