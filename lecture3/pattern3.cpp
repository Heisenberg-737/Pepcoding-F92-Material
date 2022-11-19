#include<iostream>

using namespace std;

void mirrortriangle(int n){
    int nst=1;
    int nsp=n-1;

    for(int r=1;r<=n;r++)
    {
        for(int csp=1;csp<=nsp;csp++) cout<<" ";

        for(int cst=1;cst<=nst;cst++) cout<<"*";

        nst+=2;
        nsp--;
        cout<<endl;

    }
}

int main(int args,char **argv)
{
    int rows;
    cout<<"Enter number of rows: ";
    cin>>rows;
    
    mirrortriangle(rows);

    return 0;
}