#include <iostream>
using namespace std;
void list3Numbers(int a, int b, int c);
int main(void)
{
    int numTestCases;
    int a, b, c;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++)
    {
        cin >> a >> b >> c;
        list3Numbers(a, b, c);
    }
    return 0;
}
void list3Numbers(int a, int b, int c)
{
    if (a <= b)
    {
        if (b <= c)
            cout << a << " " << b << " " << c << endl;
        else 
        {
            if (a <= c)
                cout << a << " " << c << " " << b << endl;
            else
                cout << c << " " << a << " " << b << endl;
        }
    }
    else 
    {
        if (a <= c)
            cout << b << " " << a << " " << c << endl;
        else 
        {
            if (b <= c)
                cout << b << " " << c << " " << a << endl;
            else 
                cout << c << " " << b << " " << a << endl;
        }
    }
}