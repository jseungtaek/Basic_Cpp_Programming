#include <iostream>
using namespace std;

int main(void)
{
    int t;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int x11, y11, x12, y12, x21, y21, x22, y22, x = 0, y = 0, flag1 = 0, flag2 = 0;
        int sum = 0;
        int num[101][101] = {0};
        cin >> x11 >> y11 >> x12 >> y12 >> x21 >> y21 >> x22 >> y22;
        int len = (x12 - x11 + y12 - y11 + x22 - x21 + y22 - y21) * 2;
        for (int j = x11; j < x12; j++)
        {
            for (int k = y11; k < y12; k++)
                num[j][k]++;
        }
        for (int j = x21; j < x22; j++)
        {
            for (int k = y21; k < y22; k++)
                num[j][k]++;
        }
        for (int j = 0; j < 101; j++)
        {
            for (int k = 0; k < 101; k++)
            {   
                if (num[j][k])
                    sum++;
                if (num[j][k] == 2 && flag1 == 0)
                    x++;
                if (num[k][j] == 2 && flag2 == 0)
                    y++;
            }
            if (x)
                flag1++;
            if (y)
                flag2++;
        }
        len = len - (x + y) * 2;
        cout << sum << " " <<len << endl;
    }
    return 0;
}