#include <iostream>

using namespace std;

void Dtob2(int n, int b2)
{
    int res = 0;
    int pow = 1;
    int m = n;

    while (n != 0)
    {
        int c = n % b2;

        res = res + (pow * c);

        pow *= 10;
        n = n / b2;
    }

    cout << "\nIn base 2 =" << res << endl;
}

void b1toD(int n, int b1, int b2)
{
    int res = 0;
    int pow = 1;

    while (n != 0)
    {
        int rem = n % 10;
        res += (rem * pow);

        n /= 10;
        pow *= b1;
    }

    Dtob2(res, b2);
}

int main(int args, char **argv)
{
    int n, b1, b2;
    cout << "Enter number of n: ";
    cin >> n;
    cout << endl
         << "Enter base 1:";
    cin >> b1;
    cout << endl
         << "Enter base 2:";
    cin >> b2;

    b1toD(n, b1, b2);

    return 0;
}