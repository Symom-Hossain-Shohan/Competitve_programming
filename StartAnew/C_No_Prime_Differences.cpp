#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll r, c;
    cin >> r >> c;
    int matrix[r][c];
    ll x = 1;
    for (int i = 1; i < r; i += 2)
    {
        for (int j = 0; j < c; j++)
        {
            matrix[i][j] = x;
            x++;
        }
    }

    for (int i = 0; i < r; i += 2)
    {
        for (int j = 0; j < c; j++)
        {
            matrix[i][j] = x;
            x++;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
    cout << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}