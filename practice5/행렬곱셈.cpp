#include <iostream>
#include <cstdlib>
using namespace std;

int** arr(int **a, int n, int m)
{
    a = new int* [n];
    for (int i=0;i<n;i++)
        a[i] = new int [m];
    return a;
}

int** zeroset(int **a, int n, int m)
{
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            a[i][j] = 0;
    }
    return a;
}

int** put_matrix(int **a, int n, int m)
{
    int tmp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> tmp;
            a[i][j] = tmp;
        }
    }
    return a;
}

void del(int **a,int n)
{
    for (int i=0;i<n;i++)
        delete [] a[i];
    delete [] a;
}

int main(void)
{
    int t;

    cin >> t;
    for (int i=0;i<t;i++)
    {
        int r, s, t;
        int **A,**B,**C;
        cin >> r >> s >> t;
        A = arr(A, r, s);
        B = arr(B, s, t);
        C = arr(C, r, t);
        A = put_matrix(A, r, s);
        B = put_matrix(B, s, t);
        C = zeroset(C, r, t);
        for (int j=0;j<r;j++)
        {
            for(int k=0;k<t;k++)
            {
                for(int m=0;m<s;m++)
                {
                    C[j][k] += A[j][m] * B[m][k];
                }
            }
        }
        for (int j=0;j<r;j++)
        {
            for(int k=0;k<t;k++)
                cout << C[j][k] << " ";
            cout << endl;
        }
        del(A, r);
        del(B, s);
        del(C, r);
    }
    return 0;
}