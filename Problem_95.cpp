// Find the missing and repeating number
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {4, 3, 6, 2, 1, 6,7};

    // std::cout << "The repeating element is ";
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     if (arr[abs(arr[i]) - 1] > 0)
    //         arr[abs(arr[i]) - 1] = - arr[abs(arr[i]) - 1];
    //     else
    //         std::cout << abs(arr[i]) << endl;
    // }

    // std::cout << "The missing element is ";
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     if (arr[i] > 0)
    //         std::cout << i + 1;
    // }

    int XOR = 0, x = 0, y = 0;
    for (int i = 0; i < arr.size(); i++)
        XOR ^= arr[i];
    for (int i = 1; i <= arr.size(); i++)
        XOR ^= i;
    int set_bit_no = XOR & ~(XOR - 1);

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] & set_bit_no)
            x ^= arr[i];
        else
            y ^= arr[i];
    }
    for (int i = 1; i <= arr.size(); i++)
    {
        if (i & set_bit_no)
            x ^= i;
        else
            y ^= i;
    }

    std::cout << "Repeating element is " << y << endl;
    std::cout << "Missing element is " << x << endl;

    return 0;
}