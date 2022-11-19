#include <iostream>

using namespace std;

int main(int args,char **argv)
{
    cout<<"Odd numbers:";
    for(int i=1;i<=100;i+=2)
    {
        cout<<i<<" ";
    }
    
    cout<<endl<<"Even Numbers:";
    for(int i=2;i<=100;i+=2)
    {
        cout<<i<<" ";
    }

    cout<<endl<<"Table of two:";
    for(int i=1;i<=10;i++) cout<<2*i<<" ";


}