#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 1; 
vector<ll> tree[N];
vector<ll> depth(N);
vector<ll> ans(N);

ll eval_depth(ll src, ll par)
{
    ll src_depth = 0; 
    for(auto child: tree[src])
    {
        if(child != par)
        {
            src_depth = max(src_depth , 1 + eval_depth(child, src)); 
        }
    }

    return depth[src] = src_depth; 
}

void treeDistance(ll src, ll par, ll par_ans)
{
    vector<ll> prefixMax, suffixMax; 
    for(auto child: tree[src])
    {
        if(child != par)
        {
            prefixMax.push_back(depth[child]); 
             suffixMax.push_back(depth[child]); 
        }
    }

    for(int i=1;i<(int)prefixMax.size(); i++) prefixMax[i] = max(prefixMax[i], prefixMax[i-1]);  
    for(int i=(int)suffixMax.size()-2; i>=0; i--) suffixMax[i] = max(suffixMax[i], suffixMax[i+1]); 

    int c_no = 0; 
    for(auto child: tree[src])
    {
        if(child != par)
        {
            ll prefixPartial = (c_no == 0 ? INT_MIN : prefixMax[c_no-1]); 
            ll suffixPartial = (c_no == (int)suffixMax.size()-1 ? INT_MIN : suffixMax[c_no+1]); 
            ll partialAns = 1LL + max(par_ans, max(prefixPartial, suffixPartial));  
            treeDistance(child, src, partialAns); 
            c_no++; 
        }
    }


    ans[src] = max(par_ans + 1, depth[src]); 
}


void solve()
{
    ll n; 
    cin >> n; 
    for(int i=1;i<n; i++)
    {
        ll u, v; 
        cin >> u >> v; 
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    eval_depth(1, 0);

    treeDistance(1, 0, -1);
    for(int i=1;i<=n; i++) cout << ans[i] <<  ' ';
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