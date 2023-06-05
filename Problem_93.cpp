// Middle of three elements using minimum comparisons
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 30, b = 40, c = 10;
    int x = a - b, y = b - c, z = c - a;
    if (x * y > 0)
        std::cout << "Middle Element is " << b;
    else if (y * z > 0)
        std::cout << "Middle Element is " << c;
    else
        std::cout << "Middle Element is " << a;

    return 0;
}