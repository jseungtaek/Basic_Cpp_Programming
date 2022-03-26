#include <iostream>
using namespace std;

int angleClock(int h, int m);

int main()
{
    int t,H,M;

    cin >> t;
    for (int i=0;i<t;i++)
    {
        cin >> H >> M;
        cout << angleClock(H,M) << endl;
    }
    return 0;
}

int angleClock(int h, int m)
{
    int degree;

    h = h * 30 + m * 0.5;
    m = m * 6;

    if (h > m)
        degree = h - m;

    else
        degree = m - h;

    if (degree > 180)
        degree = 360 - degree;

    return degree;
}