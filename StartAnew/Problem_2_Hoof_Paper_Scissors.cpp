#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define all(a) a.begin(), a.end()
#define x first
#define y second
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
ll dp[100001][30][4];
int isgood(int a, int b)
{
    if (a == 0 && b == 2)
        return 1;
    else if (a == 1 && b == 0)
        return 1;
    else if (a == 2 && b == 1)
        return 1;
    else
        return 0;
}
int final(int i, int k, int curr, vi &a)
{
    if (i == a.size())
        return 0;
    else if (i == 0)
    {
        int t1 = isgood(a[i], 0) + final(i + 1, k, 0, a);
        int t2 = isgood(a[i], 1) + final(i + 1, k, 1, a);
        int t3 = isgood(a[i], 2) + final(i + 1, k, 2, a);
        return dp[i][k][curr] = max(t1, max(t2, t3));
    }
    else if (dp[i][k][curr] != -1)
        return dp[i][k][curr];
    else
    {
        if (isgood(a[i], curr))
        {
            return dp[i][k][curr] = 1 + final(i + 1, k, curr, a);
        }
        else if (k > 0)
        {
            if (curr == 0)
            {
                int t1 = isgood(a[i], 1) + final(i + 1, k - 1, 1, a);
                int t2 = isgood(a[i], 2) + final(i + 1, k - 1, 2, a);
                int t3 = isgood(a[i], curr) + final(i + 1, k, curr, a);
                return dp[i][k][curr] = max(t1, max(t2, t3));
            }
            else if (curr == 1)
            {
                int t1 = isgood(a[i], 0) + final(i + 1, k - 1, 0, a);
                int t2 = isgood(a[i], 2) + final(i + 1, k - 1, 2, a);
                int t3 = isgood(a[i], curr) + final(i + 1, k, curr, a);
                return dp[i][k][curr] = max(t1, max(t2, t3));
            }
            else
            {
                int t1 = isgood(a[i], 1) + final(i + 1, k - 1, 1, a);
                int t2 = isgood(a[i], 0) + final(i + 1, k - 1, 0, a);
                int t3 = isgood(a[i], curr) + final(i + 1, k, curr, a);
                return dp[i][k][curr] = max(t1, max(t2, t3));
            }
        }
        else
            return dp[i][k][curr] = final(i + 1, k, curr, a);
    }
}
int main()
{
    // your code goes here
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        char t;
        cin >> t;
        if (t == 'P')
            a[i] = 0;
        else if (t == 'H')
            a[i] = 1;
        else
            a[i] = 2;
    }
    memset(dp, -1, sizeof dp);
    cout << final(0, k, -1, a) << "\n";
    return 0;
}