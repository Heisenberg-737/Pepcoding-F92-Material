#include <iostream>
#include <vector>

using namespace std;

int mazePath_Memo(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er && sc == ec)
    {
        dp[sr][sc] = 1;
        return 1;
    }

    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    // if (dp.size() == dp[0].size() && dp[sr][sc] != 0) //optimisation for square matrix
    //     return dp[sr][sc];

    int count = 0;
    if (sr + 1 <= er)
    {
        count += mazePath_Memo(sr + 1, sc, er, ec, dp);
    }

    if (sc + 1 <= ec)
    {
        count += mazePath_Memo(sr, sc + 1, er, ec, dp);
    }

    if (sc + 1 <= ec && sr + 1 <= er)
    {
        count += mazePath_Memo(sr + 1, sc + 1, er, ec, dp);
    }

    dp[sr][sc] = count;

    // if (dp.size() == dp[0].size())  //optimisation for sqaure matrix
    //     dp[sr][sc] = count;

    return count;
}

int mazePath_Tabu(int er, int ec)
{
    vector<vector<int>> dp(er + 1, vector<int>(ec + 1, 0));

    for (int sr = er; sr >= 0; sr--)
    {
        for (int sc = ec; sc >= 0; sc--)
        {
            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int count = 0;

            if (sr + 1 <= er)
                count += dp[sr + 1][sc];

            if (sc + 1 <= ec)
                count += dp[sr][sc + 1];

            if (sr + 1 <= er && sc + 1 <= ec)
                count += dp[sr + 1][sc + 1];

            dp[sr][sc] = count;
        }
    }

    return dp[0][0];
}

int mazePathMulti_Memo(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er && sc == ec)
    {
        dp[sr][sc] = 1;
        return 1;
    }

    if (dp[sr][sc] != 0)
        return dp[sr][sc];
    if (dp.size() == dp[0].size() && dp[sc][sr] != 0)
        return dp[sc][sr];

    int count = 0;

    for (int jump = 1; sr + jump <= er; jump++)
    {
        count += mazePathMulti_Memo(sr + jump, sc, er, ec, dp);
    }

    for (int jump = 1; sc + jump <= ec; jump++)
    {
        count += mazePathMulti_Memo(sr, sc + jump, er, ec, dp);
    }

    for (int jump = 1; sc + jump <= ec && sr + jump <= er; jump++)
    {
        count += mazePathMulti_Memo(sr + jump, sc + jump, er, ec, dp);
    }

    dp[sr][sc] = count;

    if (dp.size() == dp[0].size())
        dp[sc][sr] = count;

    return count;
}

int mazePathMulti_Tabu(int er, int ec)
{
    vector<vector<int>> dp(er + 1, vector<int>(ec + 1, 0));

    for (int sr = er; sr >= 0; sr--)
    {
        for (int sc = ec; sc >= 0; sc--)
        {
            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int count = 0;

            for (int jump = 1; sr + jump <= er; jump++)
                count += dp[sr + jump][sc];

            for (int jump = 1; sc + jump <= ec; jump++)
                count += dp[sr][sc + jump];

            for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
                count += dp[sr + 1][sc + 1];

            dp[sr][sc] = count;
        }
    }

    return dp[0][0];
}

void solve()
{
    //vector<vector<int>> dp(3 + 1, vector<int>(3 + 1, 0));
    //cout << "Count: " << mazePath_Memo(0, 0, 2, 2, dp);
    // cout << "Count: " << mazePath_Tabu(2, 2) << endl;
    cout << "Count: " << mazePathMulti_Tabu(2, 2) << endl;
}

int main(int args, char **argv)
{
    solve();

    return 0;
}