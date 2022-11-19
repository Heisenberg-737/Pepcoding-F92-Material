#include <iostream>

using namespace std;

int main(int args,char **argv)
{
    int p,r,t,si;

    p=1000;
    r=4;
    t=2;

    si=(p*r*t)/100;

    cout<<"Simple Interest is: "+to_string(si)<<endl;
}