#include <iostream>

using namespace std;


int main(int args,char **argv)
{
    int n;
    cout<<"Enter number of bulbs: ";
    cin>>n;

    cout<<"\nDisplaying bulbs which are ON: ";
    for(int i=1;i*i<=n;i++) cout<<i*i<<" ";

    return 0;
}