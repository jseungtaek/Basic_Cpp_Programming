#include <iostream>
using namespace std;

int main(void)
{
    int t;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int y, m, d, days = 4, flag = 0;
        int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        cin >> y >> m >> d;
        for (int j = 1582; j < y; j++)
        {
            if (j % 4 == 0 && j % 100 != 0 || j % 400 == 0)
                days += 366;
            else
                days += 365;
        }
        if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        {
            month[1] = 29;
        }
        for (int j = 0; j < m - 1; j++)
        {
           days += month[j];
        }
        days += d;
        days %= 7;
        cout << days << endl;
    }
    return 0;
}