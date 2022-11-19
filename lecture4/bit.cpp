#include <iostream>

using namespace std;

int main(int args,char **argv)
{
    int n;
    cout<<"Enter number of n: ";
    cin>>n;

    int m=n;

    int res=0;
    int pow=1;

    while(n!=0)
    {
        int c=n%2;

        res=res+(pow*c);

        pow*=10;
        n=n/2;
    }

    cout<<"\nDisplaying in binary: "<<res;

    int result=0;
    int two=1;


    while(m!=0)
    {
        int rem=m%10;
        m/=10;
        result+=rem*two;
        two*=2;
        
    }

    cout<<"\nIn decimal ="<<result;
    return 0;
}