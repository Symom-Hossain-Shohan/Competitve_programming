#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e5 + 1; 
ll ar[N];

unordered_set<int>* st; 

void init(ll n)
{
    int h = (ceil) (log2(n)); 

    h = (2*pow(2, h)) + 5; 
    st = new unordered_set<int> [h];
}

void buildTree(int s, int e, int index)
{
    if(s==e) 
    {
        st[index].insert(ar[s]); 
        return; 
    }

    ll mid = (s+e)/2; 

    buildTree(s, mid, 2*index); 
    buildTree(mid+1, e, 2*index+1); 

    st[index].insert(st[2*index].begin(), st[2*index].end()); 
    st[index].insert(st[2*index+1].begin(), st[2*index+1].end()); 
    return; 

}

unordered_set<int> query(ll s, ll e, ll l, ll r, ll index)
{
    unordered_set<int> left, right, res; 
    if(e<l or s>r) return res; 

    if(s>=l and e<=r) return st[index]; 

    ll mid = (s+e)/2; 
    left = query(s, mid, l, r, 2*index); 
    right = query(mid+1, e, l, r, 2*index+1); 

    res.insert(left.begin(), left.end()); 
    res.insert(right.begin(), right.end()); 

    return res; 
}

void solve()
{
    ll n, q; 
    cin >> n >> q; 
    for(int i=1;i<=n; i++) cin >> ar[i]; 

    init(n);

    buildTree(1, n, 1); 

    while(q--)
    {
        ll i, j; 
        cin >> i >> j; 
        cout << query(1, n, i, j, 1).size() << endl;  
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ":\n"; 
        solve();
    }
    return 0;
}