#include <iostream>
using namespace std;

int main(void)
{
    int t;
    int size;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> size;
        int x, y, r = size / 2;
        for (y = r; y >= -r; y--)
        {
            int abs_y = abs(y);
            for (x = -r; x <= 0; x++)
            {
                if (x < -abs_y)
                {
                    if (x % 2 == 0)
                        cout << "0";
                    else
                        cout << "1";
                }
                else
                {
                    if (y % 2 == 0)
                        cout << "0";
                    else
                        cout << "1";
                }
            }
            for (; x <= r; x++)
            {
                if (x >= abs_y)
                {
                    if (x % 2 == 0)
                        cout << "0";
                    else
                        cout << "1";
                }
                else
                {
                    if (y % 2 == 0)
                        cout << "0";
                    else
                        cout << "1";
                }
            }
            cout << endl;
        }
    }
}