#include <iostream>
using namespace std;

int main()
{
    int t, n, max, min, num;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            if (j == 0)
            {
                max = num;
                min = num;
            }
            if (max < num)
                max = num;
            if (min > num)
                min = num;
        }
        cout << max << " " << min << endl;
    }
    return 0;
}