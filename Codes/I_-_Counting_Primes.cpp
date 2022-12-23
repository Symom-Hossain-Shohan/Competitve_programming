#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MX = 100001 ; 
int tree[4*MX] ; 
int ar[MX] ; 
int prop[4*MX] ;

vector<bool> is_prime(1000001, true) ; 


void sieve()
{
     
    for(int i = 3 ; i*i<= 1000000;i+= 2)
    {
        if(is_prime[i])
        {
            for(int j= i*i; j<=1000000;j+=2*i)
            {
                is_prime[j] = false ; 
            }
        }
    }
    is_prime[0]=is_prime[1]=false ; 
    for(int i=4;i<=1000000;i+=2) is_prime[i] =false ;
    
}

void build_tree(int node, int b, int e)
{
    if(b==e)
    {
        if(is_prime[ar[b]]) tree[node] = 1 ; 
        else tree[node] = 0 ; 
        return ; 
    }

    int left = 2*node  ;
    int right = 2*node + 1 ; 
    int mid = (b+e)/2 ; 

    build_tree(left, b, mid) ; 
    build_tree(right , mid+1, e) ; 

    tree[node] = tree[left] + tree[right] ; 
}

void update(int node, int b, int e, int i, int j, int v)
{
    if(prop[node]!=0)
    {
        int p = prop[node] ; 
        prop[node] = 0 ; 
        tree[node] = is_prime[p]*(e-b+1) ; 
        if(b!=e) 
        {
            prop[2*node] = p ; 
            prop[2*node+1] = p ; 
        }
    }

    if(i>e or j<b) return ; 
    if(i<=b and j>=e)
    {
        tree[node] = is_prime[v]*(e-b+1) ; 
        if(b!=e)
        {
            prop[2*node] = v ; 
            prop[2*node+1] = v ; 
        }
        return ; 
    }

    int left = 2*node ; 
    int right = 2*node + 1 ; 
    int mid = (b+e)/2 ; 

    update(left , b, mid, i, j, v) ; 
    update(right, mid+1, e, i, j, v) ; 
    tree[node] = tree[left] + tree[right] ; 
}

int query(int node, int b, int e, int i, int j)
{
    if(prop[node]!=0)
    {
        int p = prop[node] ; 
        prop[node] = 0 ; 
        tree[node] = is_prime[p]*(e-b+1)  ;
        if(b!=e)
        {
            prop[2*node] = p ;
            prop[2*node+1] = p ; 
        }
    }

    if(i>e or j<b) return 0 ; 
    if(i<=b and j>=e) return tree[node]  ;
    int left = 2*node ; 
    int right = 2*node + 1 ; 
    int mid = (b+e)/2 ; 

    return query(left, b, mid, i, j) + query(right, mid+1, e, i, j) ;
}


void solve()
{
    memset(tree, 0, sizeof tree) ; 
    memset(prop, 0, sizeof prop) ;
    int n , q ;
    cin >> n >> q ; 
    for(int i=1 ;i<=n;i++) cin >> ar[i]  ;
    
    build_tree(1, 1, n) ; 
    while(q--)
    {
        int choice ; 
        cin >> choice ; 
        if(choice == 0) 
        {
            int i, j, v ; 
            cin >> i >> j >> v ; 
            update(1, 1, n, i, j, v) ; 
        }
        else 
        {
            int i, j ;
            cin >> i >> j ;
            cout << query(1, 1, n, i, j) << endl ;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    sieve() ;
    
    for(ll t=1;t<=tc;t++)
    {
        cout << "Case " << t << ":\n" ;
        solve();
    }
    return 0;
}