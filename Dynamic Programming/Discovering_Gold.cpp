#include <bits/stdc++.h>
using namespace std;

int n; 
int arr[200];
long double dp[200];

long double solve(int pos){
    if(pos == n) return arr[n];
    if(dp[pos] >= 0) return dp[pos];

    long double v = 0;
    for(int i=1; i<=6; i++){
        if(pos+i <= n){
            int dv = min(6, n - pos);
            v += (1.0/dv) * solve(pos+i);
        }
    }
    dp[pos] = arr[pos] + v;
    return dp[pos];
}
int main() {
    int t, cs = 1; cin>>t;
    while(cs <= t){
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>arr[i];
        }
        for(int i=0; i<=110; i++) dp[i] = -1;
        cout << fixed << setprecision(9);
        cout<<"Case "<<cs<<": "<<solve(1)<<endl;
        cs++;
    }
}