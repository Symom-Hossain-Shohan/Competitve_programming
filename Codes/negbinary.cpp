#include <algorithm>
#include<bits/stdc++.h>
#include <type_traits>
#include <vector>
using namespace std;

typedef long long ll;

ll n, m;
vector<ll> Rank, Parent;

int find_set(int i)
{
    if (Parent[i] == i) return i;
    else return Parent[i] = find_set(Parent[i]);
}


void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (Rank[a] < Rank[b])
        {
            Parent[a] = b;
            Rank[b] += Rank[a];
        }
        else
        {
            Parent[b] = a;
            Rank[a] += Rank[b];
        }
    }
}

void solve()
{
    cin >> n >> m;
    Rank.resize(n+5, 1);
    Parent.resize(n+5);
    for(int i=0;i<=n+2;i++) Parent[i] = i; 

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        union_set(u, v);
    }

    ll q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (find_set(a) == find_set(b)) cout << "yes\n";
        else cout << "no\n";
    }
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