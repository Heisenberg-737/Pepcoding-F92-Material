#include<iostream>
#include<vector>

using namespace std;

void swapr(vector<vector<int>>& arr)
{
    int r1=0;
    int r2=arr.size()-1;

    while(r1<r2)
    {
        for(int c=0;c<arr[0].size();c++) swap(arr[r1][c],arr[r2][c]);
        r1++; r2--;
    }
}

void swapc(vector<vector<int>>& arr)
{
    int c1=0;
    int c2=arr[0].size()-1;

    while(c1<c2)
    {
        for(int r=0;r<arr.size();r++) swap(arr[r][c1],arr[r][c2]);
        c1++; c2--;
    }
}

void transpose(vector<vector<int>>& arr)
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
         swap(arr[i][j],arr[j][i]);
    }
}

void Display(vector<vector<int>>& arr)
{
    for(vector<int> ar: arr)
    {
        for(int ele:ar) cout<<ele<<" ";

        cout<<endl;
    }


}

void rotate90(vector<vector<int>>& arr)
{
    char ch;

    transpose(arr);
    cout<<"Rotate clock wise(c) or anti-clock wise(ac) ?"; cin>>ch;

    if(ch=='c') { swapc(arr); Display(arr); }
    else { swapr(arr); Display(arr); }
    
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

    rotate90(arr);
    return 0;

}