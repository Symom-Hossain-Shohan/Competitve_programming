#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mx=200005;
int n,q;
ll a[mx], tree[mx*4][2], lazy[mx*4];
string s;
void build(int node, int start, int end)
{
    if(start==end)
    {
        if(s[start-1]=='1')
        {
            tree[node][1]=a[start];
            tree[node][0]=0;
        }
        else
        {
            tree[node][1]=0;
            tree[node][0]=a[start];
        }
        lazy[node]=0;
        return;
    }
    int mid=(start+end)/2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node][1]=tree[node*2][1]^tree[node*2+1][1];
    tree[node][0]=tree[node*2][0]^tree[node*2+1][0];
    lazy[node]=0;
}
void update(int node, int start, int end, int l, int r)
{
    if(lazy[node]%2!=0)
    {
        swap(tree[node][0], tree[node][1]);
        if(start!=end)
        {
            lazy[node*2]  =(lazy[node*2]  +lazy[node])%2;
            lazy[node*2+1]=(lazy[node*2+1]+lazy[node])%2;
        }
        lazy[node]=0;
    }
    if(start>r or end<l)
    {
        return;
    }
    if(start>=l and end<=r)
    {
       swap(tree[node][0], tree[node][1]);
       if(start!=end)
       {
            lazy[node*2]   =(lazy[node*2]+1)%2;
            lazy[node*2+1] =(lazy[node*2+1]+1)%2;
       }
       return;
    }

    int mid=(start+end)/2;
    update(2*node, start, mid, l, r);
    update(2*node+1, mid+1, end, l, r);
    tree[node][0]=tree[node*2][0]^tree[node*2+1][0];
    tree[node][1]=tree[node*2][1]^tree[node*2+1][1];
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cin>>s;
    build(1,1,n);
    cin>>q;
    vector<ll>ans;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1) ///update
        {
            int l, r;
            cin>>l>>r;
            update(1,1,n, l, r);
        }
        else ///query
        {
            int v;
            cin>>v;
            ans.push_back(tree[1][v]);
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

