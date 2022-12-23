#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
read:
    while(t--){
        int n, m;
        string s;
        cin >> n >> m >> s;
        int last = -m;
        vector<int> row(m);
        vector<bool> col(m, false);
        int x = 0;
        for(int i = 0; i < n * m; i++){
            if(s[i] == '1'){
                last = i;
                if(!col[i % m]) col[i % m] = 1, x++;
            }
            if(i - last < m) row[i % m]++;
            cout << row[i % m] + x << ' ';
        }
        cout << endl;
    }
    return 0;
}