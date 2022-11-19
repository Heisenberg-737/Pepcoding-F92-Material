#include <iostream>

using namespace std;

void add(int a, int b)
{

    int res = 0;
    int pow = 1;
    int carry = 0;

    while (a != 0 || b != 0 || carry != 0)
    {
        int rem = a % 10 + b % 10 + carry;

        carry = rem / 8;
        rem %= 8;

        a /= 10;
        b /= 10;

        res += rem * pow;

        pow *= 10;
    }

    cout << endl
         << "After addition = " << res;
}

int main(int args, char **argv)
{
    int a, b;

    cout << "Enter number1 and number2 in octal: ";
    cin >> a >> b;

    add(a, b);

    return 0;
}