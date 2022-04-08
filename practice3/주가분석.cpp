#include <iostream>
using namespace std;

int main(void)
{
    int t;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int cnt = 0;
        int f, s = -1;
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            if (j == 0)
            {
                f = num;
                continue;
            }
            if (f < num)
            {
                if (s == -1)
                {
                    s = num;
                    continue;
                }
                else if (s == num)
                    continue;
                else if (s < num)
                {
                    f = s;
                    s = num;
                }
                else if (f < s && s > num)
                {
                    cnt++;
                    f = num;
                    s = -1;
                }
            }
            else
            {
                if (f < s && s > num)
                {
                    cnt++;
                    f = num;
                    s = -1;
                }
                else if (f == num)
                    continue;
                else if (f > num)
                    f = num;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}