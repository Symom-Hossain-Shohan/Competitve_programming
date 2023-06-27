#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1e5 + 5;

ll ar[N];
ll tree[4 * N + 5][3];
ll lazy[4 * N + 5];


void build(ll s, ll e, ll index)
{
    if(s==e)
    {
        tree[index][0] = 1; 
        return; 
    }

    ll mid = (s+e)/2; 
    build(s, mid, 2*index); 
    build(mid+1, e, 2*index+1); 

    tree[index][0] = tree[2*index][0] + tree[2*index+1][0]; 
    tree[index][1] = tree[2*index][1] + tree[2*index+1][1]; 
    tree[index][2] = tree[2*index][2] + tree[2*index+1][2]; 
    return; 
}


void update(ll s, ll e, ll l, ll r, ll inc, ll index)
{
    if (lazy[index])
    {
        ll x = lazy[index] % 3;
        ll z = tree[index][0];
        ll o = tree[index][1];
        ll t = tree[index][2];
        if (x == 1)
        {
            tree[index][0] = t;
            tree[index][1] = z;
            tree[index][2] = o;
        }
        else if (x == 2)
        {
            tree[index][0] = o;
            tree[index][1] = t;
            tree[index][2] = z;
        }

        if (s != e)
        {
            lazy[2 * index] += x;
            lazy[2 * index + 1] += x;
        }
        lazy[index] = 0;
    }

    if (e < l or s > r)
        return;
    if (s >= l and e <= r)
    {
        ll z = tree[index][0];
        ll o = tree[index][1];
        ll t = tree[index][2];

        tree[index][0] = t;
        tree[index][1] = z;
        tree[index][2] = o;

        if(s!=e)
        {
            lazy[2 * index]++;
            lazy[2 * index + 1]++;
        }
        return; 
    }

    ll mid = (s+e)/2; 

    update(s, mid, l, r, 1, 2*index); 
    update(mid+1, e, l, r, 1, 2*index+1); 

    tree[index][0] = tree[2*index][0] + tree[2*index+1][0]; 
    tree[index][1] = tree[2*index][1] + tree[2*index+1][1]; 
    tree[index][2] = tree[2*index][2] + tree[2*index+1][2]; 

    return; 

}



ll query(ll s, ll e, ll l, ll r, ll index)
{
    if (lazy[index])
    {
        ll x = lazy[index] % 3;
        ll z = tree[index][0];
        ll o = tree[index][1];
        ll t = tree[index][2];
        if (x == 1)
        {
            tree[index][0] = t;
            tree[index][1] = z;
            tree[index][2] = o;
        }
        else if (x == 2)
        {
            tree[index][0] = o;
            tree[index][1] = t;
            tree[index][2] = z;
        }

        if (s != e)
        {
            lazy[2 * index] += x;
            lazy[2 * index + 1] += x;
        }
        lazy[index] = 0;
    }

    if(e<l or s>r) return 0; 
    if(s>=l and e<=r) return tree[index][0]; 
    ll mid = (s+e)/2; 

    ll left = query(s, mid, l, r, 2*index); 
    ll right = query(mid+1, e, l, r, 2*index+1); 

    return left + right; 
}

void solve()
{
    ll n, q;
    cin >> n >> q;

    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));
    build(1, n, 1); 

    while (q--)
    {
        ll choice;
        cin >> choice;
        if (choice == 0)
        {
            ll i, j;
            cin >> i >> j;
            i++, j++;
            update(1, n, i, j, 1, 1);
        }
        else
        {
            ll i, j; 
            cin >> i >> j; 
            i++, j++; 
            cout << query(1, n, i, j, 1) << "\n"; 
        }
    }

    //for(int i = 0;i<40; i++)  cout << tree[i][0] << ' '; 
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