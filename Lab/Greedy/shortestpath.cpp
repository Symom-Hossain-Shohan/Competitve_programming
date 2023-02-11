#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v[10000];
int vis[10000];
int dis[10000];

int main()
{
    int i, j, k;
    cin >> n;
    cin >> m;

    for (i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<int> q;
    

    int src, dest;
    cin >> src >> dest;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 1;
        for (auto x : v[u])
        {

            if (vis[x] == 0)
            {
                vis[x] = 1;
                dis[x] += dis[u] + 1;
                q.push(x);
            }
        }
    }

    
    cout << dis[dest] << endl;
}