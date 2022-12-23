#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n ; 
vector<int> adj[4002] ;
vector<pair<int,int>> black_white(4002) ; 
string s ;

void dfs(int node)
{
    if(s[node-1]=='W') 
    {
        black_white[node]  = {1,0} ;
    }
    else 
    {
        black_white[node] = {0,1} ;
    } 
    for(auto child: adj[node]) 
    {
        if(child!=node) 
        {
            dfs(child) ; 
            black_white[node].first+= black_white[child].first ; 
            black_white[node].second+= black_white[child].second;
        }
    }
    
    
}

void solve()
{
    cin >> n ; 
    for(int i=1;i<=n;i++) adj[i].clear()  ; 
    black_white.resize(n, {0,0})  ;   
    for(int i=2;i<=n;i++)
    {
        int x ;
        cin >> x ; 
        adj[x].push_back(i) ; 
    }
    cin >> s ; 


    dfs(1) ; 
    int ans = 0 ; 
    for(int i=1;i<=n;i++) 
    {
        if(black_white[i].first==black_white[i].second) ans++;
    }

    cout << ans << endl; 

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll tc=1;
    cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}