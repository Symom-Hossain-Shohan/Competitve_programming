#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MX = 100001 ; 
string s ; 
int tree[4*MX] ; 
int prop[4*MX] ; 

int n ;

void build_tree(int node, int b, int e)
{
    if(b==e)
    {
        tree[node] = s[b] - '0' ;
        return ; 
    }

    int left = 2*node ; 
    int right = 2*node + 1  ;
    int mid = (b+e)/2 ; 

    build_tree(left, b, mid) ; 
    build_tree(right, mid+1, e) ;

    tree[node] = tree[left] + tree[right] ;
}

void update(int node, int b, int e, int i, int j) 
{
    if(prop[node]!=0)
    {
        int p = prop[node] ; 
        prop[node] = 0 ; 
        if(p%2==1)
        {
            tree[node] = (e-b+1) - tree[node] ;
        }
        if(b!=e) 
        {
            prop[2*node]+= p ;
            prop[2*node+1] += p ; 
        }
    }

    if(i>e or j<b) return ; 
    if(i<=b and j>=e) 
    {
        tree[node] = (e-b+1) - tree[node] ; 
        if(b!=e)
        {
            prop[2*node]++ ; 
            prop[2*node+1]++; 
        }
        return ; 
    }

    int left = 2*node ; 
    int right = 2*node + 1  ;
    int mid = (b+e)/2 ; 

    update(left, b, mid, i, j) ; 
    update(right, mid+1, e, i, j) ; 
    tree[node] = tree[left] + tree[right] ; 
}

int query(int node, int b, int e, int i, int j)
{
    if(prop[node]!=0)
    {
        int p = prop[node] ; 
        prop[node] = 0 ; 
        if(p%2) tree[node] = (e-b+1) - tree[node] ; 

        if(b!=e)
        {
            prop[2*node]+= p ;
            prop[2*node+1]+= p ; 
        }
    }
    if(i>e or j<b) return 0 ; 
    if(i<=b and j>=e) 
    {
        return tree[node] ;
    }

    int left = 2*node ; 
    int right = 2*node + 1 ; 
    int mid = (b+e)/2 ; 

    return query(left, b, mid, i, j) + query(right, mid+1, e, i, j) ; 
}

void solve()
{
    memset(tree, 0, sizeof tree) ; 
    memset(prop, 0, sizeof prop) ; 

    cin >> s ; 
    reverse(s.begin(),s.end()) ; 
    s.push_back('0') ; 
    reverse(s.begin(),s.end()) ; 
    n = s.size() - 1 ;

    build_tree(1, 1, n) ; 

    int q ; 
    cin >> q ; 

    while(q--)
    {
        char choice  ;
        cin >> choice ; 
        if(choice == 'I')
        {
            int i, j ;
            cin >> i >> j ; 
            update(1, 1, n, i, j) ; 
        }
        else 
        {
            int i ;
            cin >>  i;
            cout << query(1, 1, n, i, i) << endl ; 
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
        cout << "Case " << t << ":\n" ;
        solve();
    }
    return 0;
}