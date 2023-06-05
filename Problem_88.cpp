// Recursively print all the combinations of sentences from a list of list of words
#include <bits/stdc++.h>
using namespace std;
#define ROW 3
#define COL 3

void printHelper(string wordList[ROW][COL], int R, int C, string output[ROW])
{
    output[R] = wordList[R][C];

    if (R == ROW - 1)
    {
        for (int i = 0; i < ROW; i++)
            std::cout << output[i] << " ";
        std::cout << endl;
        return;
    }

    for (int i = 0; i < COL; i++)
    {
        if (wordList[R + 1][i] != "")
        {
            printHelper(wordList, R + 1, i, output);
        }
    }
}

void print(string wordList[ROW][COL])
{
    string output[ROW];

    for (int i = 0; i < COL; i++)
    {
        if (wordList[0][i] != "")
            printHelper(wordList, 0, i, output);
    }
}

int main()
{
    string wordList[ROW][COL] = {{"you", "we"},
                                    {"have", "are"},
                                    {"sleep", "eat", "drink"}};
    print(wordList);

    return 0;
}

