#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t,arr[3];

    cin >> t;
    for (int i=0;i<t;i++)
    {
        for (int i=0;i<t;i++)
            cin >> arr[i];
        sort(arr, arr+t);
        for (int i=0;i<t;i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}