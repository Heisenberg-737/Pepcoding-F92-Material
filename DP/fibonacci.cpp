#include <iostream>
#include <vector>

using namespace std;

void multiply(vector<vector<int>> &F, vector<vector<int>> &M)
{
    int w = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int x = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int y = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int z = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = w;
    F[0][1] = x;
    F[1][0] = y;
    F[1][1] = z;
}

void power(vector<vector<int>> &F, int n)
{
    if (n <= 1)
        return;

    vector<vector<int>> M = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if ((n & 1) != 0)
        multiply(F, M);
}

int fibo(int n)
{
    if (n == 0)
        return 0;

    vector<vector<int>> M = {{1, 1}, {1, 0}};

    power(M, n);

    return M[0][1];
}

int main(int args, char **argv)
{
    int f = fibo(5);
    cout << f << endl;
    return 0;
}