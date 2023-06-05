// Given an array consisting of 0s, 1s and 2s and we need to sort that array without using a sorting algorithm
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> test = {1, 0, 1, 1, 0, 2, 0, 2, 2, 0,  1, 2, 1};

    // Brute Force way
    // vector<int> countarr = {0, 0, 0};
    // for (int i = 0; i < test.size(); i++)
    // {
    //     countarr[test[i]]++;
    // }

    // int k = 0;
    // for (int i = 0; i < countarr.size(); i++)
    // {
    //     while (countarr[i] > 0)
    //     {
    //         test[k] = i;
    //         countarr[i]--;
    //         k++;
    //     }
    // }

    // for (int i = 0; i < test.size(); i++)
    //     std::cout << test[i] << " ";

    // Dutch National Flag Algorithm
    int low = 0, mid = 0, high = test.size() - 1;
    while (mid <= high)
    {
        switch (test[mid])
        {
        case 0:
            swap(test[mid++], test[low++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(test[mid], test[high--]);
            break;
        
        default:
            break;
        }
    }

    for (int i = 0; i < test.size(); i++)
        std::cout << test[i] << " ";

    return 0;
}