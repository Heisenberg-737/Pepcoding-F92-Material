#include <iostream>

using namespace std;

int digit(int n)
{
    int count = 0;

    while (n != 0)
    {
        n /= 10;
        count++;
    }

    return count;
}

int power(int n, int p)
{
    int r = 1;

    for (int i = 1; i <= p; i++)
    {
        r = r * n;
    }

    return r;
}

void rotate(int n, int r)
{
    r = r % digit(n);
    if (r < 0)
        r += digit(n);

    int ans = ((n % power(10, digit(n) - r)) * power(10, r)) + (n / power(10, digit(n) - r));

    cout << "\nRotated number= " << ans << endl;
}

int main(int args, char **argv)
{
    int n, r;

    cout << "Enter n & r:";
    cin >> n >> r;

    rotate(n, r);
}