#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "MyRational.h"
using namespace std;
void testSimpleCase();
void testDataFromFile();
int main()
{
    testSimpleCase();
    testDataFromFile();
}
void testSimpleCase()
{
    myRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
    cout << frac1 << " " << frac2 << " " << frac3 << " "
         << frac4 << " " << frac5 << endl;
    cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;
    // Check arithmetic operators
    cout << frac1 * frac2 << " "
         << frac1 + frac3 << " "
         << frac2 - frac1 << " "
         << frac3 / frac2 << endl;
    //Check comparison operators
    cout << ((frac1 < frac2) ? 1 : 0) << " "
         << ((frac1 <= frac2) ? 1 : 0) << " "
         << ((frac1 > frac2) ? 1 : 0) << " "
         << ((frac1 >= frac2) ? 1 : 0) << " "
         << ((frac1 == frac2) ? 1 : 0) << " "
         << ((frac1 != frac2) ? 1 : 0) << " "
         << ((frac2 < frac3) ? 1 : 0) << " "
         << ((frac2 <= frac3) ? 1 : 0) << " "
         << ((frac2 > frac3) ? 1 : 0) << " "
         << ((frac2 >= frac3) ? 1 : 0) << " "
         << ((frac2 == frac3) ? 1 : 0) << " "
         << ((frac2 != frac3) ? 1 : 0) << endl;
    cout << (frac6 = frac3) << " ";
    cout << (frac6 += frac3) << " ";
    cout << (frac6 -= frac3) << " ";
    cout << (frac6 *= frac3) << " ";
    cout << (frac6 /= frac3) << endl;
    cout << -frac6 << endl;
    frac6 = (++frac4) + 2;
    frac7 = 2 + (frac4++);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;
    frac6 = (--frac4) - 2;
    frac7 = 2 - (frac4--);
    cout << frac4 << " " << frac6 << " " << frac7 << endl;
    cout << 2 * frac3 << " " << frac3 * 2 << " "
         << 2 / frac3 << " " << frac3 / 2 << endl;
}
void testDataFromFile() //유리수 오름차순 출력
{
    int t;
    ifstream fin("input.txt");
    fin >> t;
    for (int i=0;i<t;i++)
    {
        int n, num, den;
        fin >> n;
        myRational *arr = new myRational [n];
        for (int j=0;j<n;j++)
        {
            fin >> num >> den;
            arr[j] = myRational(num, den);
        }
        sort(arr, arr+n);
        for (int j=0;j<n;j++)
            cout << arr[j] << " ";
        cout << endl;
        delete arr;
    }
}