// Second most repeated word sequence
#include <bits/stdc++.h>
using namespace std;

string getSecondMostFrequentWord(vector<string> strs)
{
    unordered_map<string, int> freqTable;
    pair<string, int> maximum, answer;
    maximum.second = INT_MIN;

    for (int i = 0; i < strs.size(); i++)
    {
        freqTable[strs[i]]++;
    }

    for (auto it = freqTable.begin(); it != freqTable.end(); it++)
    {
        if (it->second > maximum.second)
        {
            answer.first = maximum.first;
            answer.second = maximum.second;
            maximum.first = it->first;
            maximum.second = it->second;
        }
        else if (it->second > answer.second && it->second != maximum.second)
        {
            answer.first = it->first;
            answer.second = it->second;
        }
    }
    return answer.first;
}

int main()
{
    vector<string> test = { "ccc", "aaa", "ccc", "ddd", "aaa", "aaa" };

    std::cout << getSecondMostFrequentWord(test);

    return 0;
}