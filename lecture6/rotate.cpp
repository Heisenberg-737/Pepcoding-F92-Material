#include<iostream>
#include<vector>

using namespace std;

void reverse(vector<int>& arr,int l,int r)
{
    while(l<=r)
    {
        int temp=arr[l];
        arr[l]=arr[r];
        arr[r]=temp;
        l++;
        r--;
    }
}

void rotate(vector<int>& arr,int r)
{
    r%=arr.size();
    if(r<0) r+=arr.size();
    
    reverse(arr,0,r-1);
    reverse(arr,r,arr.size()-1);      
    reverse(arr,0,arr.size()-1);
}

int main(int args,char **argv)
{
    int n,r;

    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> arr(n,0);

    cout<<"Enter the values in the array: ";

    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<endl<<"Enter r: "; cin>>r;

    rotate(arr,r);

    cout<<"\nArray after rotation: ";

    for(int ele:arr) cout<<ele<<" ";

    return 0;
    
}
