#include<bits/stdc++.h>
# define ll long long
# define pb push_back
# define all(a) a.begin(),a.end()
# define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
# define test int t;cin>>t;while(t--)
# define loop(n) for(int i=0;i<n;i++)
# define input(arr,n);for(int i=0;i<n;i++)cin>>arr[i];
# define nline "\n"
int MOD=1000000007;
using namespace std;
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

ll helper(ll i,ll x,ll m,vector<ll>&arr,vector<vector<ll>>&dp)
{
  
  if(i==(ll)arr.size())
  {
    return 1; 
  }
  if(dp[i][x]!=-1)
    return dp[i][x];
  if(arr[i]==0)
  {
    ll ans1 = helper(i+1,x,m,arr,dp)%MOD;
    ll ans2=0;
    if(x-1>=1)
    ans2 = helper(i+1,x-1,m,arr,dp)%MOD;
    ll ans3=0;
    if(x+1<=m)
      ans3 = helper(i+1,x+1,m,arr,dp)%MOD;

    return dp[i][x] = (ans1+ans2+ans3)%MOD;


  }
  else
  {
    if(abs(arr[i]-x)<=1)
    {
      return dp[i][x] = helper(i+1,arr[i],m,arr,dp)%MOD;
    }
    else return dp[i][x]= 0;
  }

}
void solve()
{
  
  ll n,m;
  cin>>n>>m;

  vector<ll>arr(n);
  input(arr,n);
  ll ans=0;
  
  vector<vector<ll>>dp(100001,vector<ll>(101,-1));
  if(arr[0]==0)
  {
    
    for(int i=1;i<=m;i++)
    {
      ans = (ans + helper(1,i,m,arr,dp)%MOD)%MOD;
    }
  }
  else
  {
  ans = helper(1,arr[0],m,arr,dp)%MOD;
  }
  cout<<ans;  
  //-----------------tabulation------------------
  // for(int i=1;i<=m;i++)
  //   dp[n][i]=1;

  // for(int i=n-1;i>=1;i--)
  // {
  //   for(int x=1;x<=m;x++)
  //   {
  //     if(arr[i]==0)
  //     {
  //       ll ans1 = dp[i+1][x]%MOD;
  //       ll ans2=0;
  //       if(x-1>=1)
  //       ans2 = dp[i+1][x-1]%MOD;
  //       ll ans3=0;
  //       if(x+1<=m)
  //         ans3 = dp[i+1][x+1]%MOD;
  //       dp[i][x] = (ans1+ans2+ans3)%MOD;


  //     }
  //     else
  //     {
  //       if(abs(arr[i]-x)<=1 )
  //       {
  //         dp[i][x] = dp[i+1][arr[i]] %MOD;
  //       }
  //       else dp[i][x]= 0;
  //     }
  //   }
  // }
  // ll ans=0;
  // if(arr[0]==0)
  // {
  //   for(int i=1;i<=m;i++){
  //     ans = (ans + dp[1][i])%MOD;
  //   }

  // }
  // else ans = dp[1][arr[0]];
  // cout<<ans;
}

 
int main()
{
  flash
  // test
  solve();
  return 0;
}