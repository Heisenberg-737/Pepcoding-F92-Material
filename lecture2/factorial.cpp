#include <iostream>

using namespace std;

int fact(int n)
{
    int r = 1;

    for (int i = 2; i <= n; i++)
    {
        r *= i;
    }

    return r;
}

void ncr()
{
    int n, r;

    cout << "Enter n and r:";
    cin >> n >> r;

    int ans = fact(n) / ((fact(n - r)) * (fact(r)));

    cout << "\nAnswer of Combination:" << ans << endl;
}

int main(int agrs, char **argv)
{
    int n;

    cout << "Enter n for factorial:";
    cin >> n;

    cout << "\nFactorial= " << fact(n) << endl;

    ncr();

    return 0;
}