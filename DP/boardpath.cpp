#include <iostream>
#include <vector>

using namespace std;

int board_path(int start, int tar, vector<int> &dp)
{
    if (start == tar)
    {
        dp[start] = 1;
        return 1;
    }

    if (dp[start] != 0)
        return dp[start];

    int count = 0;

    for (int dice = 1; dice <= 6; dice++)
    {
        if (start + dice <= tar)
            count += board_path(start + dice, tar, dp);
    }

    dp[start] = count;
    return count;
}

int main(int args, char **argv)
{
    int tar;

    cin >> tar;

    vector<int> dp(tar + 1, 0);

    cout << "Count: " << board_path(0, tar, dp) << endl;

    for (int ele : dp)
        cout << ele << " ";
    return 0;
}