#include <iostream>
using namespace std;

int main()
{
    int t, n, num;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            sum += num;
        }
        cout << sum << endl;
    }
    return 0;
}