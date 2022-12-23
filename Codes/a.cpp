#include<bits/stdc++.h>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

typedef long long ll;
int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };

void solve()
{
	ll n, m;
	cin >> n >> m;
	char mtx[n + 5][m + 5];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) cin >> mtx[i][j];
	}


	int   x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int dist[n + 1][m + 1], visited[n + 1][m + 1];
	memset(dist, -1, sizeof(dist));
	memset(visited, 0, sizeof(visited));
	dist[x1][y1] = 0 ;
	visited[x1][y1] = 1;
	queue<pair<int, int>> q;
	q.push({x1, y1});
	while (!q.empty())
	{
		ll parx = q.front().first, pary = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			ll x = parx + dRow[i];
			ll y = pary + dCol[i];
			if (x >= 1 and x <= n and y >= 1 and y <= m and mtx[x][y] == '*' and !visited[x][y])
			{
				dist[x][y] = dist[parx][pary] + 1;
				visited[x][y] = 1;
				q.push({x, y});
			}
		}
	}
	if (visited[x2][y2]) cout << dist[x2][y2] << endl;
	else cout << -1 << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll tc = 1;
	//cin >> tc;
	for (ll t = 1; t <= tc; t++)
	{
		solve();
	}
	return 0;
}
