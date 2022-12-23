#include<bits/stdc++.h>
#include <cstring>
#include <ios>
using namespace std;

typedef long long ll;
ll n, root, lft[50], rght[50];
map<ll, ll> mp;

void Pre_traversal(int node)
{
    cout << " " << node;
    if (lft[node] != -1)
    {
        Pre_traversal(lft[node]);
    }
    if (rght[node] != -1)
    {
        Pre_traversal(rght[node]);
    }
}

void In_traversal(int node)
{
    if (lft[node] != -1)
    {
        In_traversal(lft[node]);
    }
    cout << " " << node;
    if (rght[node] != -1)
    {
        In_traversal(rght[node]);
    }
}

void Post_traversal(int node)
{
    if (lft[node] != -1)
    {
        Post_traversal(lft[node]);
    }
    if (rght[node] != -1)
    {
        Post_traversal(rght[node]);
    }
    cout << ' ' << node;
}

void solve()
{
    //memset(lft, -1, sizeof(lft));
    //memset(rght, -1, sizeof(rght));
    for (int i = 0; i < 50; i++) lft[i] = -1, rght[i] = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll N, l, r;
        cin >> N >> l >> r;
        mp[l] = 1, mp[r] = 1;
        lft[N] = l;
        rght[N] = r;
    }
    int root ;
    for (int i = 0; i < n; i++)
    {
        if (!mp[i])
        {
            root = i;
            break;
        }
    }
    cout << "Preorder\n";
    Pre_traversal(root);
    cout << endl;
    cout << "Inorder\n";
    In_traversal(root);
    cout << endl;
    cout << "Postorder\n";
    Post_traversal(root);
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}