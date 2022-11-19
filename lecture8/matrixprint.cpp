#include<iostream>
#include<vector>

using namespace std;

void spiralprint(vector<vector<int>>& arr)
{
    int minc=0,minr=0;
    int maxr=arr.size()-1,maxc=arr[0].size()-1;
    int tne=arr.size()*arr[0].size();

    while(tne!=0)
    {
        for(int i=minc;i<=maxc && tne!=0;i++)
        {
            cout<<arr[minr][i]<<" ";
            tne--;
        }
        minr++;

        for(int i=minr;i<=maxr && tne!=0;i++)
        {
            cout<<arr[i][maxc]<<" ";
            tne--;
        }
        maxc--;

        for(int i=maxc;i>=minc && tne!=0;i--)
        {
            cout<<arr[maxr][i]<<" ";
            tne--;
        }
        maxr--;

        for(int i=maxr;i>=minr && tne!=0;i--)
        {
            cout<<arr[i][minc]<<" ";
            tne--;
        }
        minc++;
    }


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

    cout<<endl;

    spiralprint(arr);
    return 0;

}