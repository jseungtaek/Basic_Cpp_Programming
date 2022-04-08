#include <iostream>
using namespace std;

int main(void)
{
    int t;

    cin >> t;
    for (int i=0;i<t;i++)
    {
        int a,b,c,d, total_len = 0, overlap_len = 0; 
        cin >> a >> b >> c >> d;
        int arr[101] = {0};
        for (int j=a;j<b;j++)
            arr[j]++;
        for (int j=c;j<d;j++)
            arr[j]++;
        a = a < c ? a : c;
        b = b > d ? b : d;
        for (int j=a;j<b;j++)
        {
            if (arr[j])
                total_len++;
            if (arr[j] > 1)
                overlap_len++;
        }
        cout << overlap_len << " " << total_len << endl;
    }
    return 0;
}