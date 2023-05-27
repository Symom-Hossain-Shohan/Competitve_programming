#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> Parent, Rank; 


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
    Rank.resize(10, 1);
    Parent.resize(10);
    for(int i=0;i<10; i++) Parent[i] = i; 

    union_set(2, 3);
    union_set(2, 7);

    cout << find_set(2) << ' ' << find_set(7); 
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