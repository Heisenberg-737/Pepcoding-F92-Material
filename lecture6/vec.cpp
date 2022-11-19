#include <iostream>
#include <vector>

using namespace std;

int minimum(vector<int> &arr)
{
    int small = arr[0];

    for (int i = 0; i < arr.size(); i++)
    {
        small = min(small, arr[i]);
    }

    return small;
}

int maximum(vector<int> &arr)
{
    int large = arr[0];

    for (int i = 0; i < arr.size(); i++)
    {
        large = max(large, arr[i]);
    }

    return large;
}

bool find(vector<int> &arr, int data)
{
    int flag = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == data)
            flag = 1;
    }

    if (flag == 1)
        return true;
    else
        return false;
}

int main(int args, char **argv)
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> ar(n, 0);

    cout << "\nEnter values in the array: ";

    for (int i = 0; i < n; i++)
        cin >> ar[i];

    int data;
    cout << endl
         << "Enter the data to be found: ";
    cin >> data;

    bool ans = find(ar, data);

    if (ans == 1)
        cout << endl
             << "Element is present!!";
    else
        cout << endl
             << "Element is not present!!";

    cout << endl
         << "Maximum number in the array: " << maximum(ar);
    cout << endl
         << "Minimum number in the array: " << minimum(ar);

    return 0;
}