#include<iostream>
#include<cstdlib>
using namespace std;

char board[8][8];
void set()
{
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            if ((i == 3 && j == 3) || (i == 4 && j == 4))
                board[i][j] = 'O';
            else if ((i == 3 && j == 4) || (i == 4 && j == 3))
                board[i][j] = 'X';
            else
                board[i][j] = '+';
        }
    }
}

void Othello(int s, int t, int num)
{
    char c;
    s -= 1; t -= 1;
    if (num%2)
    {
        board[s][t] = 'O';
        c = 'O';
    }
    else
    {
        board[s][t] = 'X';
        c = 'X';
    }

    for (int i = t + 1; i <= 7; i++) // 수평 오른쪽
    {
        if (board[s][i] == '+')
            break;

        if (board[s][i] == c)
        {
            for (int j = t; j < i; j++)
                board[s][j] = c;
            break;
        }
    }
    for (int i = t - 1; i >= 0; i--) // 수평 왼쪽
    {
        if (board[s][i] == '+')
            break;

        if (board[s][i] == c)
        {
            for (int j = t; j > i; j--)
                board[s][j] = c;
            break;
        }
    }
    for (int i = s + 1; i <= 7; i++) // 수직 아래쪽
    {
        if (board[i][t] == '+')
            break;

        if (board[i][t] == c)
        {
            for (int j = s; j < i; j++)
                board[j][t] = c;
            break;
        }
    }
    for (int i = s - 1; i >= 0; i--) // 수직 위쪽
    {
        if (board[i][t] == '+')
            break;

        if (board[i][t] == c)
        {
            for (int j = s; j > i; j--)
                board[j][t] = c;
            break;
        }
    }
    for (int i = s - 1, j = t + 1; i >= 0 && j <= 7; i--, j++) // 오른쪽 위쪽 대각
    {
        if (board[i][j] == '+')
            break;

        if (board[i][j] == c)
        {
            for (int k = s, l = t; k > i && l < j; k--, l++)
                board[k][l] = c;
            break;
        }
    }
    for (int i = s - 1, j = t - 1; i >= 0 && j >= 0; i--, j--) //왼쪽 위쪽 대각
    {
        if (board[i][j] == '+')
            break;

        if (board[i][j] == c)
        {
            for (int k = s, l = t; k > i && l > j; k--, l--)
                board[k][l] = c;
            break;
        }
    }
    for (int i = s + 1, j = t + 1; i <= 7 && j <= 7; i++, j++) // 오른쪽 아래 대각
    {
        if (board[i][j] == '+')
            break;

        if (board[i][j] == c)
        {
            for (int k = s, l = t; k < i && l < j; k++, l++)
                board[k][l] = c;
            break;
        }
    }
    for (int i = s + 1, j = t - 1; i <= 7 && j >= 0; i++, j--) // 왼쪽 아래 대각
    {
        if (board[i][j] == '+')
            break;

        if (board[i][j] == c)
        {
            for (int k = s, l = t; k < i && l > j; k++, l--)
                board[k][l] = c;
            break;
        }
    }

}

int main(void)
{
    int testCase;
    cin >> testCase;
    for (int i=0;i<testCase;i++)
    {
        int n, s, t, b_cnt = 0, w_cnt = 0;
        set();
        cin >> n;
        for (int j=0;j<n;j++)
        {
            cin >> s >> t;
            Othello(s, t, j);
        }
        for (int j=0;j<8;j++)
        {
            for (int k=0;k<8;k++)
            {
                if (board[j][k] == 'O')
                    w_cnt++;
                else if (board[j][k] == 'X')
                    b_cnt++;
            }
        }
        cout << b_cnt << " " << w_cnt << endl;
        for (int j=0;j<8;j++)
        {
            for (int k=0;k<8;k++)
                cout << board[j][k];
            cout << endl;
        }
    }
    return 0;
}