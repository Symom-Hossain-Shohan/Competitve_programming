#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MX = 100001 ; 
ll tree [MX] ;

void update(int idx, int val, int n)
{
    while(idx<=n)
    {
        tree[idx]+= val ; 
        idx += (idx & -idx) ;
    }
}

ll query(int idx, int n)
{
    ll sum = 0 ; 
    while(idx>0)
    {
        sum+= tree[idx] ; 
        idx -= (idx & -idx) ;
    }
    return sum ;
}

void solve()
{
    int n, q ;
    cin >> n >> q ; 
    memset(tree, 0 , sizeof tree) ;
    for(int i=1;i<=n;i++)
    {
        int x; 
        cin >> x ;
        update(i, x, n) ;
    }

    while(q--)
    {
        int choice ; 
        cin >> choice ; 
        if(choice==1)
        {
            int i ;
            cin >> i ;
            ll x = query(i+1, n)-query(i,n) ;
            cout << x << endl; 
            update(i+1, -x, n) ;
        }
        else if(choice==2)
        {
            int i, v ; 
            cin >> i >> v ;
            update(i+1, v, n) ;
        }
        else
        {
            int l, r ;
            cin >> l >> r ;
            cout << query(r+1, n) - query(l, n) << endl ;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        cout << "Case " << t<< ":\n" ;
        solve();
    }
    return 0;
}