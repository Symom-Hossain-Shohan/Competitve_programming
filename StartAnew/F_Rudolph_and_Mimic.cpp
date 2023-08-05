#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void print(vector<ll> v)
{
    cout << "- " << (int)v.size() << ' ';
    for (auto i : v)
        cout << i << ' ';
    cout << endl;
    cout.flush();
}

void solve()
{
    int n;
		cin >> n;
		vector<int> v(n);
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			m[v[i]]++;
		}
		vector<int> elements_to_erase;
		int ans;
		for (int i = 0; i < 5; i++) {
			if (v.size() - elements_to_erase.size() == 1) {
				cout << "! " << ans << endl;
				break;
			}
			cout << "- " << elements_to_erase.size() << " ";
			for (int j = 0; j < elements_to_erase.size(); j++) {
				cout << elements_to_erase[j] << " ";
			}
			cout << endl;
			vector<int> new_v;
			map<int, int> new_m;
			for (int j = 0; j < v.size() - elements_to_erase.size(); j++) {
				int x;
				cin >> x;
				new_v.push_back(x);
				new_m[x]++;
			}
			elements_to_erase.clear();
			int tm = -1;
			for (auto& k : new_m) {
				if (k.second > m[k.first]) {
					tm = k.first;
				}
			}
			if (tm != -1) {
				for (int j = 0; j < new_v.size(); j++) {
					if (new_v[j] != tm)
						elements_to_erase.push_back(j + 1);
					else
						ans = j + 1;
				}
				m.clear();
				m[tm] = new_m[tm];
			}
			v = new_v;
		}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}