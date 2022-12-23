#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;

void print_subsequence(string s) {
  int n = s.size();
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j <= n; j++) {
      if (i & (1 << j))
        cout << s[j];
    }
    cout << endl;
  }
}

void solve() {
  string s;
  cin >> s;
  print_subsequence(s);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll tc = 1;
  // cin >> tc;
  for (ll t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}