#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MX = 30001 ; 

int ar[MX] ; 
vector<int> tree[4*MX] ; 

void build_tree(int node, int b, int e)
{
    if(b==e)
    {
        tree[node].push_back(ar[b]) ; 
        return ; 
    }

    int left = 2*node ; 
    int right = 2*node + 1 ; 
    int mid = (b+e)/2  ;

    build_tree(left, b, mid) ; 
    build_tree(right, mid+1, e) ; 

    int i=0, j=0; 

    while(i<(int)tree[left].size() and j<(int)tree[right].size())
    {
        if(tree[left][i]<=tree[right][j])
        {
            tree[node].push_back(tree[left][i]);
            i++;
        }
        else 
        {
            tree[node].push_back(tree[right][j]);
            j++;
        }
    }

    while(i<(int)tree[left].size()) 
    {
        tree[node].push_back(tree[left][i]);
        i++;
    }

    while(j<(int)tree[right].size())
    {
        tree[node].push_back(tree[right][j]) ; 
        j++ ;
    }
}


int query(int node, int b, int e, int i, int j, int k)
{
    if(i>e or j<b) return 0 ;
    if(i<=b and j>=e)
    {
        int res = upper_bound(tree[node].begin(),tree[node].end(),k)-tree[node].begin() ;
        return (int)tree[node].size() - res ; 
    }

    int left = 2*node ; 
    int right = 2*node + 1 ; 
    int mid = (b+e)/2 ; 

    return query(left, b, mid, i, j, k) + query(right, mid+1, e, i, j, k) ; 
}

void solve()
{
    int n ;
    cin >> n ; 
    for(int i= 1;i<=n;i++) cin >> ar [i] ; 
    build_tree(1, 1, n) ;

    int q ; 
    cin >> q  ;
    while(q--)
    {
        int i, j, k ;
        cin >> i >> j >> k ; 

        cout << query(1, 1, n, i, j, k) << endl ; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}