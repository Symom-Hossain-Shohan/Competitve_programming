//https://lightoj.com/problem/guilty-prince
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m; 
char matrix[21][21];
bool visited[21][21];

int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };


ll bfs(pair<ll,ll> node)
{
    bool visited[21][21] = {false};
     


    visited[node.first][node.second] = true; 
    queue<pair<ll,ll>> q; 
    q.push(node);
    ll cnt = 1; 
    while(!q.empty())
    {
        pair<ll,ll> cur = q.front();
        q.pop();

        
        for(int i = 0;i<4;i++)
        {
            ll x = cur.first, y = cur.second; 
            x += dRow[i];
            y += dCol[i];
            if(x>=0 and x<n and y>=0  and y<m and visited[x][y]==false and matrix[x][y]!='#')
            {
                cnt++; 
                //cout << '(' << x << ' ' << y << ')' << ", ";
                visited[x][y] = true; 
                q.push({x, y});
            }
        }
    }


    return cnt; 
}



void solve()
{
    cin >> m >> n; 
    pair<ll,ll> p; 
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> matrix[i][j];
            if(matrix[i][j]=='@')
            {
                p.first = i, p.second = j ;
            }
        }
    }
    

    cout << bfs(p) << endl;  
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}