#include <iostream>
#include <vector>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

int maxRodCut(vi &price, int n)
{

    if (n <= 0)
        return 0;

    int max_ = -1e8;

    for (int cut = 0; cut < n; cut++)
    {
        max_ = max(max_, price[cut] + maxRodCut(price, n - cut - 1));
    }

    return max_;
}

//OptimalBST===============================================================================================================================



void solve()
{
    vi price = {1, 5, 8, 9, 10, 17, 17, 20};

    cout << "Max Price:" << maxRodCut(price, 8) << endl;
}

int main(int args, char **argv)
{
    solve();
    return 0;
}