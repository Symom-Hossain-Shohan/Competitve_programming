#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
	int mtx[2][2];
	ll cnt = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> mtx[i][j];
			if (mtx[i][j]) cnt++;
		}
	}
	//cout << cnt << endl; 
	if (cnt == 0) cout << 0 << endl;
	else if (cnt == 4) cout << 2 << endl;
	else cout << 1 << endl;

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll tc = 1;
	cin >> tc;
	for (ll t = 1; t <= tc; t++)
	{
		solve();
	}
	return 0;
}		