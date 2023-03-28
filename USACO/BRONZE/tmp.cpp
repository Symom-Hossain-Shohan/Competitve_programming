#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int ans = 0;
vector<int>p;
int main() {
	freopen("hoofball.in", "r", stdin);
	freopen("hoofball.out", "w", stdout);
	cin >> N;
	if (N < 4) {
		cout << 1; return 0;
	}
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		p.push_back(a);
	}
	sort(p.begin(),p.end());
	for (int i = 0; i < N-1; i++) {
		if (i == 0) {
			if (p[i + 1] - p[i] <= p[i + 2] - p[i + 1]) ans++; 
		}
		else if (i == N - 2) {
			if (p[i + 1] - p[i] < p[i] - p[i - 1])ans++; 
		}
		else{
			if (p[i + 1] - p[i] < p[i] - p[i - 1] && p[i + 1] - p[i] <= p[i + 2] - p[i + 1]) {
				ans++;
				if (i + 3 >= N&&i-2>=0) {
					if (p[i - 1] - p[i - 2] > p[i] - p[i - 1]) ans++;
				}
				else if (i - 2 < 0 && i + 3 < N) {
					if (p[i + 3] - p[i + 2] >= p[i + 2] - p[i + 1]) ans++;
				}
				else if (i + 3 >= N && i - 2 < 0)ans++;
				else if (p[i + 3] - p[i + 2] >= p[i + 2] - p[i + 1] && p[i - 1] - p[i - 2] > p[i] - p[i - 1]) ans++;
				
			}
		}
	}
	cout << ans;
}