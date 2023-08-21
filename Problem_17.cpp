// Best time to buy and sell stock
#include <bits/stdc++.h>
using namespace std;

int getMaxProfit(vector<int> prices)
{
    int max_profit = INT_MIN, min_price = prices[0], n = prices.size();

    for (int i = 1; i < n; i++)
    {
        min_price = min(prices[i], min_price);
        max_profit = max(max_profit, prices[i] - min_price);
    }

    return max_profit;
}


int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int max_profit = getMaxProfit(prices);
    cout << "Max Profit is " << max_profit << endl;

    return 0;
}