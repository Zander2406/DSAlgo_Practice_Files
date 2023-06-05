// Function to find Number of customers who could not get a computer
#include <bits/stdc++.h>
using namespace std;

int runCustomerSimulation(int computerAvailable, string customers)
{
    unordered_map<char, int> customerTracker;
    int customersMissed = 0;
    for (int i = 0; i < customers.length(); i++)
    {
        if (!computerAvailable && customerTracker[customers[i]] == 0)
            customersMissed++;
        else
        {
            if (customerTracker[customers[i]] > 0)
            {
                computerAvailable++;
                customerTracker[customers[i]]--;
            }
            else if (customerTracker[customers[i]] == 0)
            {
                computerAvailable--;
                customerTracker[customers[i]]++;
            }
        }
    }

    return customersMissed / 2;
}

int main()
{
    cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
    cout << runCustomerSimulation(1, "ABCBCA") << endl;
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl;

    return 0;
}



















