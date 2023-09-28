#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mx = 200005;
string s;
ll ar[mx], tree[4 * mx][2], lazy[4 * mx];

void buildTree(ll node, ll start, ll end)
{
    if (start == end)
    {
        if (s[start - 1] == '1')
        {
            tree[node][1] = ar[start];
            tree[node][0] = 0;
        }
        else
        {
            tree[node][0] = ar[start];
            tree[node][1] = 0;
        }
        lazy[node] = 0;
        return;
    }

    ll mid = (start + end) / 2;

    buildTree(2 * node, start, mid);
    buildTree(2 * node + 1, mid + 1, end);

    tree[node][1] = tree[2 * node][1] ^ tree[2 * node + 1][1];
    tree[node][0] = tree[2 * node][0] ^ tree[2 * node + 1][0];

    lazy[node] = 0;
}

void update(ll node, ll star, ll end, ll l, ll r)
{
    if (lazy[node] % 2 != 0)
    {
        swap(tree[node][0], tree[node][1]);
        if (star != end)
        {
            lazy[node * 2] = (lazy[node * 2] + lazy[node]) % 2;
            lazy[node * 2 + 1] = (lazy[node * 2 + 1] + lazy[node]) % 2;
        }
        lazy[node] = 0;
    }

    if (end < l or r < star)
        return;
    if (star >= l and end <= r)
    {
        swap(tree[node][0], tree[node][1]);
        if (star != end)
        {
            lazy[node * 2] = (lazy[node * 2] + 1) % 2;
            lazy[node * 2 + 1] = (lazy[node * 2 + 1] + 1) % 2;
        }
        return;
    }
    ll mid = (star + end) / 2;

    update(2 * node, star, mid, l, r);
    update(2 * node + 1, mid + 1, end, l, r);
    tree[node][1] = tree[2 * node][1] ^ tree[2 * node + 1][1];
    tree[node][0] = tree[2 * node][0] ^ tree[2 * node + 1][0];
}

void solve()
{
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> ar[i];
    // string s;
    cin >> s;

    buildTree(1, 1, n);

    ll q;
    cin >> q;
    vector<ll> ans;
    while (q--)
    {
        ll choice;
        cin >> choice;
        if (choice == 1)
        {
            ll l, r;
            cin >> l >> r;
            update(1, 1, n, l, r);
        }
        else
        {
            ll g;
            cin >> g;
            // cout << tree[1][g] << ' ';
            ans.push_back(tree[1][g]);
        }
    }
    for (auto i : ans)
        cout << i << ' ';
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