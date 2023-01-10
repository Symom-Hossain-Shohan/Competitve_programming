#include <bits/stdc++.h>
using namespace std;
int maxcrossing(vector<int> &v, int l, int m, int h)
{
    int ls = 0;
    int sum = 0;
    for (int i = m; i >= l; i--)
    {
        sum += v[i];
        if (sum > ls)
            ls = sum;
    }
    int rs = 0;
    sum = 0;
    for (int i = m; i <= h; i++)
    {
        sum += v[i];
        if (sum > rs)
            rs = sum;
    }
    return max(rs + ls - v[m], max(ls, rs));
}
int maxsum(vector<int> &v, int l, int h)
{
    if (l > h)
        return 0;
    if (l == h)
        return v[l];
    int m = (l + h) / 2;
    int x = maxsum(v, l, m - 1), y = maxsum(v, m + 1, h), z = maxcrossing(v, l, m, h);
    return max(x, max(y, z));
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int ans = maxsum(v, 0, n - 1);
    cout << ans << endl;
}