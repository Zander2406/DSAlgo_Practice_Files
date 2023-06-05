// Find the union and intersection of two sorted arrays
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> array1 = {1, 2, 3, 4, 5, 6};
    vector<int> array2 = {4, 5, 6, 7, 8, 9};

    // Union of two arrays
    // unordered_set<int> arrayUnion;
    // for (int i = 0; i < array1.size(); i++)
    //     arrayUnion.insert(array1[i]);
    // for (int i = 0; i < array2.size(); i++)
    //     arrayUnion.insert(array2[i]);
    
    // for (auto it : arrayUnion)
    //     std::cout << it << " ";

    // Intersection of two sorted arrays
    int i = 0, j = 0;
    vector<int> answer;
    while (i < array1.size() && j < array2.size())
    {
        if (i > 0 && array1[i] == array1[i - 1])
        {
            i++;
            continue;
        }

        if (array1[i] < array2[j])
            i++;
        else if (array2[j] < array1[i])
            j++;
        else
        {
            answer.push_back(array1[i]);
            i++;
            j++;
        }
    }

    for (int k = 0; k < answer.size(); k++)
        std::cout << answer[k] << " ";

    return 0;
}