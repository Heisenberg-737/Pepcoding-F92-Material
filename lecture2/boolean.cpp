#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int n)
{
    int flag = -1;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            flag = 0;
    }

    if (flag == -1)
    {
        return true;
    }

    return false;
}

int main(int args, char **argv)
{
    int n;
    bool a;

    cout << "Enter n:";
    cin >> n;

    a = isprime(n);
    cout << a;
}