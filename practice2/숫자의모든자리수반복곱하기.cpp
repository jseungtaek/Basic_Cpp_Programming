#include <iostream>
using namespace std;

int main(void)
{
    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long long n;
        long long num = 1;
        cin >> n;
        while (1)
        {
            if (n % 10 != 0)
                num *= (n % 10);
            n /= 10;
            if (n == 0 && (num > 0 && num < 10))
                break;
            if (n == 0)
            {
                n = num;
                num = 1;
            }
        }
        cout << num << endl;
    }
    return 0;
}