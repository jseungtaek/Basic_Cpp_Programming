#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(void)
{
    int t;

    cin >> t;
    for (int i=0;i<t;i++)
    {
        string name;
        int res = 0;
        int j = 0;
        cin >> name;
        int len = name.length();
        while (j < len)
        {
            if (name[j] == '_' || isalpha(name[j]))
                res = 1;
            if (isdigit(name[j]) && res==0)
            {
                break;
            }
            if (name[j] != '_' && !isalpha(name[j]) && !isdigit(name[j]))
            {
                res = 0;
                break;
            }
            j++;
        }
        cout << res << endl;
    }
    return 0;
}