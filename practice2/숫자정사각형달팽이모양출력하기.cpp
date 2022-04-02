#include <iostream>
using namespace std;
#define MAX 1001
#define MAXNUM 1000001
int map[MAX][MAX];
int num[MAXNUM];
int main(void)
{
    int t, n, a, b;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> a >> b;
        int index = 1;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
                map[j][k] = index++;
        }
        int y = 0, x = 0, sign = 1, c = 0;
        for (int q = 0; q < n; q++)
        {
            num[c++] = map[y][x];
            x += sign;
        }
        x -= 1;
        for (int w = n - 1; w > 0; --w)
        {
            for (int e = 0; e < w; ++e)
            {
                y += sign;
                num[c++] = map[y][x];
            }
            sign *= -1;
            for (int u = 0; u < w; ++u)
            {
                x += sign;
                num[c++] = map[y][x];
            }
        }
        for (int j = a - 1; j < b; j++)
            cout << num[j] << " ";
        cout << endl;
    }
    return 0;
}