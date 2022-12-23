#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MX = 100001 ; 

string ar; 

ll tree[4*MX] ;
ll prop[4*MX] ;

ll n ; 

void build_tree(ll node, ll b, ll e)
{
    if(b==e)
    {
        tree[node] = ar[b] - '0' ;
        return ; 
    }

    ll mid = (b+e)/2 ; 
    ll left = 2*node ; 
    ll right = 2*node + 1 ; 
    build_tree(left, b, mid) ; 
    build_tree(right, mid+1, e) ; 
    tree[node] = tree[left] + tree[right] ;  
}

void update(ll node, ll b, ll e, ll i, ll j)
{
    if(prop[node]!=0)
    {
        ll p = prop[node] ; 
        prop[node] = 0 ; 
        //Jodi bit flip kori taile number of 1 = total node - tree[node] 
        if(p%2) tree[node] = (e-b+1) - tree[node] ; 
        if(b!=e)
        {
            prop[2*node]++;
            prop[2*node+1]++ ; 
        }
    }

    if(i>e or j<b) return ; 
    if(i<=b and j>=e)
    {
        ll p = 1 ; 
        //Jodi bit flip kori taile number of 1 = total node - tree[node] 
        tree[node] = (e-b+1) - tree[node] ; 
        if(b!=e)
        {
            prop[2*node]++ ; 
            prop[2*node+1]++ ; 
        }
        return ; 
    }

    ll left = 2*node ; 
    ll right = 2*node + 1 ;
    ll mid = (b+e)/2 ; 
    update(left, b, mid, i, j) ; 
    update(right, mid+1, e, i, j) ; 
    tree[node] = tree[left] + tree[right] ;

}

ll query(ll node, ll b, ll e, ll i, ll j)
{
    if(prop[node]!=0)
    {
        ll p = prop[node] ; 
        prop[node] = 0 ; 
        if(p%2) tree[node] = (e-b+1)-tree[node] ; 
        if(b!=e)
        {
            prop[2*node]++ ; 
            prop[2*node+1]++ ; 
        }
    }

    if(i>e or j<b) return 0 ; 
    if(i<=b and j>=e)
    {
        return tree[node] ; 
    }

    ll left = 2*node ; 
    ll right = 2*node + 1 ; 
    ll mid = (b+e)/2 ; 
    return query(left, b, mid, i, j) + query(right, mid+1, e, i, j) ; 
}

void solve()
{
    cin >> ar ;
    //One based Index korar jonno
    reverse(ar.begin(),ar.end()) ;
    ar.push_back('0');
    reverse(ar.begin(),ar.end());
    //cout << ar << endl;
    memset(tree, 0, sizeof tree) ; 
    memset(prop, 0, sizeof prop) ;
    
    n =ar.size()-1;
    //cout << n << endl;
    

    build_tree(1, 1, n) ;

    ll q ;
    cin >> q ; 
    while(q--)
    {
        char choice ; 
        cin >> choice ; 
        if(choice == 'I')
        {
            ll i, j; 
            cin >> i >> j; 
            update(1, 1, n, i, j) ;
        }
        else 
        {
            ll i ;
            cin >> i ; 
            cout << query(1, 1, n, i, i) << endl; 
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
        cout << "Case " << t << ":\n";
        solve();
    }
    return 0;
}