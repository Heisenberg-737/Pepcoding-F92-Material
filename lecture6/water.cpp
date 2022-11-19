#include <iostream>
#include <vector>

using namespace std;

int cal(vector<int>& arr)
{
    int max_=0;
    int i=0;
    int j=arr.size()-1;
    while(i<j)
    {
        if(arr[i]<arr[j])
        {
            max_=max(max_,arr[i]*(j-i));
            i++;
        }
        else
        {
           max_=max(max_,arr[j]*(j-i));
           j--;
        }
        
    }
    return max_;

}

int main(int args,char **argv)
{
    int n;

    cout<<"Enter number of walls: "; cin>>n;

    vector<int> arr(n,0);

    cout<<"\nEnter the lenghts of the walls: ";
    for(int i=0;i<n;i++) cin>>arr[i];


    cout<<"\nMaximum water that can be stored: "<<cal(arr);

    return 0;

}