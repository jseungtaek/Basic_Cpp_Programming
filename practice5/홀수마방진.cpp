#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
using namespace std;

int** zero_set_arr(int **a, int n)
{
    a = new int* [n];
    for(int i=0;i<n;i++)
        a[i] = new int [n];
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            a[i][j] = 0;
    }
    return a;
}

void coord_re(int &coord_x, int &coord_y, int n)
{
    if (coord_y > n - 1)
        coord_y = 0;
    if (coord_x < 0)
        coord_x = n - 1;
}

void del(int **a, int n)
{
    for(int i=0;i<n;i++)
        delete [] a[i];
    delete [] a;
}

int main(void)
{
    int t,n;
    ifstream fin("input.txt");
    fin >> t;
    for(int i=0;i<t;i++)
    {
        fin >> n;
        int final_num = n * n;
        int cnt_num = 1, coord_x = 0, coord_y = n/2;
        int **arr;
        arr = zero_set_arr(arr, n);
        arr[coord_x][coord_y] = cnt_num++;
        while (n > 1)
        {
            int tmp_x = coord_x, tmp_y = coord_y;
            coord_x -= 1; coord_y += 1;
            coord_re(coord_x, coord_y, n);
            if (arr[coord_x][coord_y] == 0)
            {
                arr[coord_x][coord_y] = cnt_num;
            }
            else
            {
                coord_x = tmp_x; coord_y = tmp_y;
                coord_x += 1;
                coord_re(coord_x, coord_y, n);
                arr[coord_x][coord_y] = cnt_num;
            }
            if (arr[coord_x][coord_y] == final_num)
                break;
            cnt_num++;
        }
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
        del(arr, n);
    }
    fin.close();
    return 0;
}