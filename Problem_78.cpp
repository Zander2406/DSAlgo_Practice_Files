// Smallest window that contains all characters of string itself
#include <bits/stdc++.h>
using namespace std;

string getSubString(string str)
{
    int n = str.length();
    if (n <= 1)
        return str;
    
    // This portion is used just for counting the distinct character we have in our string
    int distinctCount = 0;
    bool visited[256] = { false };
    for (int i = 0; i < n; i++)
    {
        if (visited[str[i]] == false)
        {
            visited[str[i]] = true;
            distinctCount++;
        }
    }

    // Here we keep a start pointer and a reference start index from where our answer will start along with the length
    int start = 0, startIndex = -1, minLen = INT_MAX;
    int count = 0;

    // This array will keep track of how many character we have in our string
    int currCount[256] = { 0 };
    for (int j = 0; j < n; j++)
    {
        currCount[str[j]]++;

        // We check every time if this is the first time we have found this character
        if (currCount[str[j]] == 1)
            count++;
        
        // If we have collected all distinct characters
        if (count == distinctCount)
        {
            // We go ahead and start moving start pointer and reducing the frequency of the elements we are leaving behind
            while (currCount[str[start]] > 1)
            {
                if (currCount[str[start]] > 1)
                    currCount[str[start]]--;
                start++;
            }
            
            // Now our length will be our current index - start
            int lenWindow = j - start + 1;
            if (minLen > lenWindow)
            {
                // We store our window length if it is smaller and store the start index for this one
                minLen = lenWindow;
                startIndex = start;
            }
        }
    }

    return str.substr(startIndex, minLen);
}

int main()
{
    string characters = "aabcbcdbca";

    // Brute Force Approach
    // vector<string> substrings;
    // int answer = INT_MAX;
    // unordered_set<char> distincts;

    // for (int i = 0; i < characters.length(); i++)
    // {
    //     distincts.insert(characters[i]);
    // }

    // for (int i = 0; i < characters.length(); i++)
    // {
    //     for (int len = 1; len <= characters.length() - i; len++)
    //         substrings.push_back(characters.substr(i, len));
    // }

    // unordered_set<char> check;
    // for (int i = 0; i < substrings.size(); i++)
    // {
    //     int n = substrings[i].length();
    //     for (int j = 0; j < n; j++)
    //     {
    //         check.insert(substrings[i][j]);
    //     }

    //     if (check.size() == distincts.size())
    //     {
    //         answer = min(answer, n);
    //     }
    //     check.clear();
    // }

    // std::cout << answer;

    // Efficient Approach
    string answer = getSubString(characters);
    std::cout << answer;

    return 0;
}