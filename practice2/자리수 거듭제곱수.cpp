#include <iostream>
using namespace std;

int main(void)
{
    int t, n;
    long long num[10];

    cin >> t;
    for (int i=0;i<t;i++)
    {
        cin >> n;
        int tmp = n;
        int j = 0;
        long long sum = 0;
        while (tmp)
        {
            num[j++] = tmp % 10;
            tmp /= 10;
        }
        for(int k=0;k<j;k++)
        {
            long long _num = num[k];
            int m = j;
            while (m >= 2)
            {
                num[k] *= _num;
                m--;
            }
            sum += num[k];
        }
        if (sum == (long long)n)
            cout << "1";
        else
            cout << "0";
        cout << endl;
    }
    return 0;
}