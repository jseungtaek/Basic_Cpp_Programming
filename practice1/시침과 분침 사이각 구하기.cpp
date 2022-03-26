#include <iostream>
#include <cstdlib>
using namespace std;

int angleClock(int h, int m);

int main()
{
    int t;
    int h, m;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> h >> m;
        cout << angleClock(h, m) << endl;
    }

    return 0;
}

int angleClock(int h, int m)
{
    double _res;
    int res;

    _res = abs(30 * h - 5.5 * (double)m);
    _res = _res > 180 ? 360 - _res : _res;
    res = _res;
    return res;
}