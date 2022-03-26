#include <iostream>
using namespace std;

int main()
{
    int t,n,num,lastnum;

    cin >> t;
    for (int i=0;i<t;i++)
    {
        cin >> n;
        cin >> num;
        lastnum = num%10;
        n--;
        while (n)
        {
            cin >> num;
            lastnum *= (num%10);
            lastnum %= 10;
            n--;
        }
        cout << lastnum << endl;
    }
    return 0;
}