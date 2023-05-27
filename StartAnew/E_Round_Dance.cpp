#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5+5; 
ll Parent[N];
ll Rank[N];

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
    ll n; 
    cin >> n; 
    vector<ll> v(n);

    for(int i=0;i<=n ;i++) Parent[i] = i, Rank[i] =0; 

    for(auto &i: v) cin >> i; 
    union_set(1, v[0]); 
    for(int i = 1; i<n ;i++) union_set(v[i], i+1);
    ll mx  = 0; 
    for(int i=2; i<=n; i++) if(find_set(1)!= find_set(i)) mx++;  

    set<ll> st; 
    for(int i=1;i<=n; i++) st.insert(find_set(i)); 
    map<ll,set<ll>> mp; 
    for(int i=1;i<=n; i++)
    {
        mp[i].insert(v[i-1]); 
        mp[v[i-1]].insert(i); 
    }

    ll cnt = 0, odd = 0; 

    map<ll,vector<ll>> mpv; 

    for(int i=1; i<=n; i++)
    {
        ll x = find_set(i); 
        mpv[x].push_back(i); 
    }

    for(auto i: mpv)
    {
        bool ok = true; 
        for(auto j: i.second) if(mp[j].size()!=2) ok = false; 

        if(ok) cnt++; 
        else odd++; 
    }
    cout << cnt + (odd!=0) << ' ';

    cout << st.size() << endl;  
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}