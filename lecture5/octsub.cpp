#include <iostream>

using namespace std;

void sub(int a,int b)
{
    int large;
    if(a>b){
        large=a;

    }
    else    large=b;

    int res=0;
    int pow=1;
    int borrow=0;

    while(large!=0)
    {
        int rem=a%10-b%10+borrow;

        if(rem<0)
        {
            borrow=-1;
            rem+=8;
        }
        else borrow=0;


        a/=10;
        b/=10;
        
        res+=rem*pow;
        large/=10;

        pow*=10;

    }

    cout<<endl<<"After subtraction = "<<res;

}

int main(int args,char **argv)
{
    int a,b;

    cout<<"Enter number1 and number2 in octal: ";
    cin>>a>>b;

    sub(a,b);

    return 0;
}