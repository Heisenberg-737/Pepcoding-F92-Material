#include <iostream>

using namespace std;

void OtoD(int n)
{
   int res=0;
   int pow=1;

   while(n!=0)
   {
       int rem=n%10;
       res+=(rem*pow);

       n/=10;
       pow*=8;

   }

   cout<<"In Decimal again: "<<res;
}

void DtoO(int n)
{
    int res = 0;
    int pow = 1;
    int m=n;

    while (n != 0)
    {
        int c = n % 8;

        res = res + (pow * c);

        pow *= 10;
        n = n / 8;
    }

    cout << "\nIn Octal =" << res<<endl;

    OtoD(res);
}


int main(int args, char **argv)
{
    int n;
    cout << "Enter number of n: ";
    cin >> n;

    DtoO(n);

    return 0;
}