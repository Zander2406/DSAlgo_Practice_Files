// Transform one string to another string using minimum number of given operations.
#include <bits/stdc++.h>
using namespace std;

int stringTransform(string A, string B)
{
    if (A.length() != B.length())
        return -1;
    
    unordered_map<char, int> m;
    int n = A.length();
    for (int i = 0; i < n; i++)
        m[A[i]]++;
    
    for (int i = 0; i < n; i++)
        m[B[i]]--;
    
    for (auto it : m)
    {
        if (it.second != 0)
            return -1;
    }

    int i = A.length() - 1, j = B.length() - 1, ans = 0;

    while (i >= 0 && j >= 0)
    {
        while (i >= 0 && A[i] != B[j])
        {
            ans++;
            i--;
        }
        i--;
        j--;
    }

    return ans;
}

int main()
{
    string A = "EACBD";
    string B = "EABCD";
    cout << stringTransform(A, B);

    return 0;
}