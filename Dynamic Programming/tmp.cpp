#include <bits/stdc++.h>

using namespace std;
const int N = 107;
int sum[N], dp[N][N];

int cou(int i, int j)
{
    if(i > j)
        return 0;

    if(dp[i][j] != INT_MAX)
        return dp[i][j];

    dp[i][j] = sum[j] - sum[i-1];
    for(int c=i; c<=j; ++ c)
    {
        dp[i][j] = max(dp[i][j], sum[c] - sum[i-1] - cou(c+1, j));
        dp[i][j] = max(dp[i][j], sum[j] - sum[c-1] - cou(i, c-1));
    }

    return dp[i][j];
}

void solve(int cases)
{
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; ++ i)
        for(int j=1; j<=n; ++ j)
            dp[i][j] = INT_MAX;

    sum[0] = 0;
    for(int i=1; i<=n; ++ i)
    {
        scanf("%d", &sum[i]);
        dp[i][i] = sum[i];
        sum[i] += sum[i-1];
    }
    printf("Case %d: %d\n", cases, cou(1, n));
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; ++ i)
        solve(i);
    return 0;
}
