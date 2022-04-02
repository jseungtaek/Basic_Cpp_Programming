#include <iostream>
using namespace std;

int main(void)
{
    int t, n, j = 0, flag = 0;
    int odd_num[100] = {
        0,
    };
    cin >> t;
    for (int i = 1; i < 100; i++)
    {
        if (i % 2 != 0)
        {
            if (flag == 0)
            {
                odd_num[i] = 0;
                flag = 1;
            }
            else
            {
                odd_num[i] = 1;
                flag = 0;
            }
        }
            
    }

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int map[100][100] = {
            0,
        };
        int fill_num = odd_num[n];
        flag = 1;

        for (int j = 0; j < n; j++)
        {
            for (int k = 0 + j; k < n - j; k++)
            {
                for (int m = 0 + j; m < n - j; m++)
                {
                    map[k][m] = fill_num;
                }
            }
            if (fill_num == 1)
                fill_num = 0;
            else
                fill_num = 1;
        }
        for (int x=0;x<n;x++)
        {
            for (int y=0;y<n;y++)
                cout << map[x][y];
            cout << endl;
        }
    }
    return 0;
}