#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 5;

ll ar[N], A[N];
ll tree[4 * N + 5];

void buildTree(ll s, ll e, ll node)
{
    if (s == e)
    {
        tree[node] = ar[s];
        return;
    }

    ll mid = (s + e) / 2;
    buildTree(s, mid, 2 * node);
    buildTree(mid + 1, e, 2 * node + 1);
    tree[node] = tree[2 * node ] + tree[2 * node + 1];
    return;
}

void update(ll s, ll e, ll ix, ll val, ll node)
{
    if (s > ix or e < ix)
        return;
    if (s>=ix and e<=ix)
    {
        tree[node] = val;
        return;
    }

    ll mid = (s + e) / 2;
    update(s, mid, ix, val, 2 * node);
    update(mid + 1, e, ix, val, 2 * node + 1);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    return;
}

int query(ll s, ll e, ll qs, ll qe, ll index)
{
    if(s>=qs and e <=qe)
    {
        return tree[index]; 
    }
    if(s>qe or e<qs) return 0; 

    ll mid = (s+e)/2; 

    ll left = query(s, mid, qs, qe, 2*index); 
    ll right = query(mid+1, e, qs, qe, 2*index+1); 
    return left+right;  
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    memset(tree, 0, sizeof(tree)); 
    memset(ar, 0, sizeof(ar)); 
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        ar[i] = 1;
    }

    ll mx = 2 * n;
    buildTree(1, mx, 1);

    while (k--)
    {
        char c;
        cin >> c;
        if (c == 'a')
        {
            ll x;
            cin >> x;
            n++;
            A[n] = x;
            update(1, mx, n, 1, 1);
        }

        else 
        {
            ll l = 1, r = mx, ans = 0; 
            ll ix; 
            cin >> ix; 
            while(l<=r)
            {
                ll mid = (l+r)/2; 
                ll q = query(1, mx, 1, mid, 1) ;
                if(q>=ix)
                {
                    ans = mid; 
                    r = mid-1; 
                }
                else l = mid+1; 
            }

            if(ans)
            {
                cout << A[ans] << endl; 
                update(1, mx, ans, 0, 1); 
            }
            else cout << "none\n"; 
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ":\n";
        solve();
    }
    return 0;
}