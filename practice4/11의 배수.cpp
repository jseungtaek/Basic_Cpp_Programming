#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void)
{
    int t;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int arr[100] = {-1};
        int j = 1;
        int k = 2;
        int a = 0;
        char num[100];
        char last_num;
        int flag = 0;
        cin >> num;
        int total_len = strlen(num) - 1;
        arr[a++] = num[total_len] - '0';
        while (1)
        {
            int len = strlen(num);
            if (len == 2)
            {
                last_num = num[len - j];
                num[len - j] = '\0';
                len = strlen(num);
                if (num[len - j] == last_num)
                    flag = 1;
            }
            if (len == 1)
                break;
            last_num = num[len - j];
            num[len - j] = '\0';
            len = strlen(num);
            if (num[len - j] < last_num)
            {
                if (num[len - k] == '0')
                {
                    int b;
                    int cnt = 0;
                    for (b = len - k; b >= 0; b--)
                    {
                        if (num[b] == '0')
                            cnt++;
                        else
                            break;
                    }
                    if (cnt)
                    {
                        num[len - k - cnt] -= 1;
                        for (int m = len - k; m > b; m--)
                        {
                            num[m] = '9';
                        }
                    }
                    arr[a] = num[len - j] + 10 - last_num;
                }
                else
                {
                    num[len - k] = num[len - k] - 1;
                    arr[a] = num[len - j] + 10 - last_num;
                }
            }
            else
            {
                arr[a] = num[len - j] - last_num;
            }
            num[len - j] = arr[a] + '0';
            a++;
        }
        if(flag==1)
        {
            if (arr[total_len - 1] == 0)
                total_len--;
            for (int w=total_len - 1;w>=0;w--)
                    cout << arr[w];
        }
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}