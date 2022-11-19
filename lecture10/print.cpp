#include <iostream>

using namespace std;

void printnum(int n)
{
    if (n == 0)
    {
        cout << "BASE ->" << n << endl;
        return;
    }

    cout << "HI ->" << n << endl;
    printnum(n - 1);
    cout << "BYE ->" << n << endl;
}

int main(int args, char **argv)
{
    printnum(10);

    return 0;
}
