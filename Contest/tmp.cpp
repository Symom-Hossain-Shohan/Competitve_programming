///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;

#define                           ll                          long long
#define                           int                         ll
#define                           ld                          long double
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           nd(a,b,c)                   mp(mp(a,b),c)
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
 
const ll inf=2e18;
const int mod=1e9+7;
const int M=52;

int n,a[M];

void solve()
{
    cin>>n;
    f(i,1,n)cin>>a[i];

    map<int,int>cnt;
   
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int gap=a[j]-a[i];
            int sq_gap=sqrt(gap)+1;
            for(int k=1;k<=sq_gap;k++)
            {
                  if(gap%k==0)
                  {   
                      bool flag=0;

                      int upv=k;
                      int umv=gap/k;
                      
                      if(umv>upv)swap(umv,upv);

                      int u=(upv+umv);
                      if(u%2)flag=1;
                      u=u/2;

                      int v=upv-u;

                      int usq=u*u;
                      int vsq=v*v;

                      int ux=usq-a[j];
                      int vx=vsq-a[i];

                      if(ux!=vx)flag=1;

                      if(ux<0 || ux>1e18)flag=1;

                      if(flag==0)
                      {
                          cnt[ux]++;
                      }


                  }
            }
        }
    }
    
    map<int,int>cnt_ase;

    for(auto z:cnt)
    {
        int p=z.si;
        cnt_ase[2*p]=1;
    }

    for(int i=n;i>=1;i--)
    {
          int q=i*(i-1);
          if(cnt_ase.count(q))
          {
              cout<<i<<"\n";
              return ;
          }
    }

    cout<<"1\n";
    return ;
}
 
 int32_t main()
 
{
    fast
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
 
}
