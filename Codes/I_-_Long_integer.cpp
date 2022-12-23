#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx  = 1e6+1, mod = 1e9+7; 
int tree[4*mx];
string s;

void build_tree(ll node, ll b, ll e)
{
    if(b==e) 
    {
         
        tree[node]=(s[b]-'0')%mod;
         
        return;
    }

    ll left =  2*node ;
    ll right = 2*node + 1 ;
    ll mid = (b+e)/2 ;
    build_tree(left, b, mid) ;
    build_tree(right, mid+1, e) ;
    //tree right e koyta
    ll x = tree[right];
    ll p = 1; 
    while(x)
    {
        p*=10; 
        x/=10; 
    }
    if(tree[left]==0&&x==0)
    {
        tree[node]=100;
    }
    else if(x==0)
    {
        tree[node]=tree[left]*10;
    }
    else 
        tree[node] = (tree[left]*p + tree[right])%mod ;
}

void update(ll node, ll b, ll e, ll i, ll newvalue)
{
    if( i > e || i < b ) return ;
    if(b==e) 
    {
        cout << tree[node] << endl; 
        cout <<  b << endl; 
        cout << node << endl; 
        tree[node] = (newvalue)%mod;
        return ;
    }

    ll left =  2*node ;
    ll right = 2*node + 1 ;

    ll mid = (b+e)/2;

    update(left, b, mid, i, newvalue) ;
    update(right, mid+1, e, i, newvalue) ;
    ll x = tree[right], p = 1; 
    while(x)
    {
        p*=10; 
        x/=10; 
    }
    if(tree[left]==0&&x==0)
    {
        tree[node]=100;
    }
    else if(x==0)
    {
        tree[node]=tree[left]*10;
    }
    else 
        tree[node] = (tree[left]*p + tree[right])%mod ;
}

ll query(ll node, ll b, ll e, ll i, ll j)
{
    if(i>e or j<b ) return 0 ;
    if(b>=i and e<=j ) return tree[node]%mod ;

    ll left = 2*node ;
    ll right = 2*node + 1 ;
    ll mid = (b+e)/2 ;
    ll query1 = query(left, b, mid, i, j) ;
    ll query2 = query(right, mid+1, e, i, j) ;
    ll x = query2, p = 1; 
    while(x)
    {
        p*=10; 
        x/=10; 
    }
    if(query1==0&&x==0)
    {
        return 100; 
    }
    else if(x==0)
    {
        return (query1*10)%mod; 
    }
    else 
        return (query1*p + query2)%mod ;

}

void solve()
{
     
    cin >> s; 
    s = "#"+s; 
    build_tree(1, 1, (int)s.size()-1); 
    int q; 
    cin >> q; 
    int n = s.size()-1; 
    // for(int i=1;i<10;i++) cout << tree[i] << ' ';
    // cout << endl; 
    
    while(q--)
    {
        char c; 
        cin >> c; 
        if(c=='+')
        {
            n+=1; 
            ll x; 
            cin >> x; 
             
            s.push_back('0'+x);
            //cout << s << endl;
            build_tree(1, 1, (int)s.size()-1); 
            cout << tree[1] << endl; 
             
        }
        else 
        {
            s.pop_back(); 
            //cout << s << endl; 
            build_tree(1, 1, (int)s.size()-1); 
            //cout << query(1, 1, (int)s.size()-1, 1, (int)s.size()-1) << endl;
            cout << tree[0] << endl; 
        }
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