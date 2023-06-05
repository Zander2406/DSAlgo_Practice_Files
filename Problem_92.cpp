// Square root of an integer
#include <bits/stdc++.h>
using namespace std;

int countSquares(int N)
{
    int n = sqrt(N);
    if (n * n == N)
        return n - 1;
    return n;
}

int main()
{
    int N = 9;
    cout << countSquares(N);

    return 0;
}