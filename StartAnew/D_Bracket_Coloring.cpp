#include <bits/stdc++.h>
using namespace std;
long long a[1200], b[1200];
int main()
{
    long long n, o, m, s, k;
    cin >> n >> o;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    while (o--)
    {
        s = 0;
        cin >> k;
        for (int i = 0; i < n; i++)
        {
            b[i] = a[i] + k;
            if (k > 0)
                k--;
        }
        if (k % 2 == 1)
            k++, b[n - 1] -= k;
        sort(b, b + n);
        k /= 2;
        for (int i = 0; i < n; i++)
            s += b[i];
        s -= k;
        m = min(b[0], s / n);
        cout << m << ' ';
    }
}