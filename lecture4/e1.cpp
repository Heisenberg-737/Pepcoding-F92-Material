#include <iostream>
#include <vector>

using namespace std;

void display(vector<int>& arr)
{
    cout<<"\nDisplaying the vector: ";
    for(int i=0;i<arr.size();i++) 
    cout<<arr[i]<<" ";

}

int main(int args,char **argv)
{
    int n;

    cout<<"Enter size of vector: ";
     cin>>n;
    
    vector<int> arr(n,0);

    cout<<"\nEnter the values in vector: ";

    for(int i=0;i<n;i++) cin>>arr[i];

    display(arr);
    return 0;
}
