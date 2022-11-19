#include <iostream>
#include <vector>

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

using namespace std;

int minJumps(vector<int> &arr)
{
    vector<int> dp(arr.size(), 1e6);
    dp[arr.size() - 1] = 0;

    for (int i = arr.size() - 2; i >= 0; i--)
    {
        int min_ = 1e6;

        for (int j = 1; j <= arr[i] && j + i < arr.size(); j++)
            min_ = min(dp[i + j], min_);

        dp[i] = min_ + 1;
    }

    return dp[0];
}

//Pair&Single=================================================================================================================================

int pairandSingle(int n)
{
    if (n == 0 || n == 1)
        return 1;

    else if (n == 2)
        return 2;

    int sum = 0;

    int a = pairandSingle(n - 1);
    int b = pairandSingle(n - 2) * (n - 1);

    sum = a + b;

    return sum;
}

int pairandSingleDP(int n)
{
    vector<int> dp(n + 1, 0);

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] += dp[i - 1];
        dp[i] += dp[i - 2] * (i - 1);
    }

    return dp[n];
}

//NumbersAndK-Sets==================================================================================================================

int divideintoKGroups(int n, int k)
{
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= k; i++)
    {
        for (int j = i; j <= n; j++)
            dp[i][j] += dp[i - 1][j - 1] + dp[i][j - 1] * i;
    }

    return dp[k][n];
}

void solve()
{
    vector<int> arr = {7, 3, 0, 4, 0, 0, 2, 1, 1, 0};

    //cout << "Min Steps: " << minJumps(arr) << endl;
    // cout << "Count: " << pairandSingle(5) << endl;

    // cout << "Count: " << pairandSingleDP(5) << endl;
    cout << "Count: " << divideintoKGroups(5, 2) << endl;
}

//Pallindrome=========================================================================================================================

vvb isPalindrome(string str)
{
    vvb isPali(str.length(), vb(str.length(), 0));

    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); i++, j++)
        {
            if (gap == 0)
                isPali[i][j] = true;

            else if (str[i] == str[j])
            {
                if (gap == 1)
                    isPali[i][j] = true;

                else if (isPali[i + 1][j - 1])
                    isPali[i][j] = true;
            }
        }
    }

    return isPali;
}

int lpSubstring(string str)
{
    vvi dp(str.length(), vi(str.length(), 0));

    vvb isPali = isPalindrome(str);

    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); i++, j++)
        {
            if (gap == 0)
                dp[i][j] = 1;

            else if (str[i] == str[j])
            {
                if (gap == 1)
                    dp[i][j] = 2;

                else if (isPali[i + 1][j - 1])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    return dp[0][str.length() - 1];
}

int lpSubsequence(string str)
{
    vector<vector<int>> dp(str.length(), vector<int>(str.length(), 0));

    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); j++, i++)
        {
            if (gap == 0)
                dp[i][j] = 1;

            else if (str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;

            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    return dp[0][str.length() - 1];
}

//MCM===================================================================================================================================

int mcm_rec(int st, int end, vi &row, vi &col)
{
    if (st == end)
        return 0;

    int min_ = 1e8;

    for (int cut = st; cut < end; cut++)
    {
        int left = mcm_rec(st, cut, row, col);
        int right = mcm_rec(cut + 1, end, row, col);

        int cost = left + row[st] * col[cut] * col[end] + right;
        min_ = min(cost, min_);
    }

    return min_;
}

int mcm_dp(vi &row, vi &col, vvi &dp)
{
    for (int gap = 0; gap < row.size(); gap++)
    {
        for (int st = 0, end = gap; end < row.size(); st++, end++)
        {
            if (gap == 0)
                continue;

            int min_ = 1e8;

            for (int cut = st; cut < end; cut++)
            {
                int left = dp[st][cut];
                int right = dp[cut + 1][end];

                int cost = left + row[st] * col[cut] * col[end] + right;
                min_ = min(cost, min_);
            }

            dp[st][end] = min_;
        }
    }

    return dp[0][row.size() - 1];
}

//MinimumPallindromicCuts==============================================================================================================

int minPallinCuts(string str, int st, int end, vvi &dp, vvb &isPali)
{
    if (st == end)
        return 0;

    int min_ = 1e8;

    for (int cut = st; cut < end; cut++)
    {
        int left = minPallinCuts(str, st, cut, dp, isPali);
        int right = minPallinCuts(str, cut + 1, end, dp, isPali);

        min_ = min(left + right + 1, min_);
    }

    return min_;
}

int minPallinCuts_01(string str, int st, int end, vvi &dp, vvb &isPali)
{
    if (st == end)
        return 0;

    if (dp[st][end] != 0)
        return dp[st][end];

    int min_ = 1e8;

    for (int cut = st; cut < end; cut++)
    {
        int left = minPallinCuts_01(str, st, cut, dp, isPali);
        int right = minPallinCuts_01(str, cut + 1, end, dp, isPali);

        min_ = min(left + right + 1, min_);
    }

    dp[st][end] = min_;

    return min_;
}

int minPallinCuts_dp(string str, int st, int end, vvi &dp, vvb &isPali)
{
    
}

void solve1()
{
}

int main(int args, char **argv)
{
    //solve();
    solve1();
    return 0;
}