#include<iostream>
#include<vector>

using namespace std;

void matrixout(vector<vector<int>>& arr)
{
    int c=0;
    int r=0;
    int dir=0;

    while(1)
    {
        dir=(dir+arr[r][c])%4;

        if(dir==0)
        {
            c++;

            if(c==arr[0].size()) 
            {
                cout<<endl<<"Exit at: ("<<r<<" , "<<(c-1)<<")"<<endl;
                break;
            }
        }    

        else if(dir==1)
        {
            r++;

            if(r==arr.size()){ cout<<endl<<"Exit at: ("<<(r-1)<<" , "<<c<<")"<<endl;
            break;}
        }

        else if(dir==2)
        {
            c--;

            if(c==-1) { cout<<endl<<"Exit at: ("<<r<<" , "<<(c+1)<<")"<<endl;
            break; }
        }

        else
        {
            r--;

            if(r==-1) { cout<<endl<<"Exit at: ("<<(r+1)<<" , "<<c<<")"<<endl;
            break; }
        }
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

    matrixout(arr);
    return 0;

}