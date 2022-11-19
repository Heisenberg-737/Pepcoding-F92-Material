#include <iostream>

using namespace std;

void oddeven(int n)
{
    if (n == 0)
    {
        cout << n << endl;
        return;
    }

    if ((n & 1) == 0)
        cout << n << endl;

    oddeven(n - 1);

    if ((n & 1) != 0)
        cout << n << endl;
}

int main(int args, char **argv)
{
    oddeven(10);

    return 0;
}
