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
        int flag = 1;
        int flag2 = n - 2;
        for (int j = 0; j < n; j++)
        {
            if (j == 0 || j == n / 2 || j == n - 1)
            {
                for (int k = 0; k < n; k++)
                {
                    if (k == 0 || k == n / 2 || k == n - 1)
                    {
                        if (j == n / 2 && k == n / 2)
                        {
                            cout << '*';
                            flag++;
                            flag2--;
                        }
                        else
                            cout << '+';
                    }
                    else
                        cout << '-';
                             
                }
                cout << endl;
            }
            else if (j > 0 && j < n / 2)
            {
                for (int k = 0; k < n; k++)
                {
                    if (k == 0 || k == n / 2 || k == n - 1)
                        cout << '|';
                    else if (k == flag)
                        cout << '\\';
                    else if (k == flag2)
                        cout << '/';
                    else
                        cout << '.';
                }
                flag++;
                flag2--;
                cout << endl;
            }
            else if (j > n / 2 && j < n - 1)
            {
                for (int k = 0; k < n; k++)
                {
                    if (k == 0 || k == n / 2 || k == n - 1)
                        cout << '|';
                    else if (k == flag)
                        cout << '\\';
                    else if (k == flag2)
                        cout << '/';
                    else
                        cout << '.';
                }
                flag++;
                flag2--;
                cout << endl;
            }
        }
    }
    return 0;
}