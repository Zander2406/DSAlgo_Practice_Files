// To check if two given strings are Isomorphic to each other
#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string A, string B)
{
    unordered_map<char, char> charCount;

    for (int i = 0; i < A.length(); i++)
    {
        if (charCount.count(A[i]))
        {
            if (charCount[A[i]] != B[i])
                return false;
        }
        else
        {
            vector<char> values;
            for (auto it : charCount)
                values.push_back(it.second);
            if (find(values.begin(), values.end(), B[i]) != values.end())
                return false;
            else
                charCount[A[i]] = B[i];
        }
    }

    return true;
}

int main()
{
    string A = "aab";
    string B = "xxy";

    if (isIsomorphic(A, B))
        std::cout << "Strings are isomorphic";
    else
        std::cout << "Strings are not isomorphic";

    return 0;
}