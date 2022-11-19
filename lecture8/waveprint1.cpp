#include<iostream>
#include<vector>

using namespace std;

void Display(vector<vector<int>>& arr)
{
    for(int i=0;i<arr.size();i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<arr[0].size();j++) cout<<arr[i][j]<<" ";
        }
        else
        {
            for(int j=arr[0].size()-1;j>=0;j--) cout<<arr[i][j]<<" ";
        }

    }
    cout<<endl;
}

int main(int args,char **argv)
{
    int n,m;
    cout<<"Enter rows and columns: ";
    cin>>n>>m;

    vector<vector<int>> arr(n,vector<int>(m,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin>>arr[i][j];
    }

    Display(arr);
    return 0;

}