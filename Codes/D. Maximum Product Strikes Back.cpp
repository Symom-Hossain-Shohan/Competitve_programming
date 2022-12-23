#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n;
    cin>>n;
    int a[n+5],neg[n+5]={0},two[n+5]={0};
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
      neg[i]+=neg[i-1];
      two[i]+=two[i-1];
      if(a[i]<0) neg[i]++;
      if(abs(a[i])==2) two[i]++;
    }
    
    int x=n,y=0,ans=0,pre=1;
    for(int i=1;i<=n;i++)
    {
      if(a[i]==0)
      {
         pre=i+1;continue;
      }
      if(two[i]-two[pre-1]>ans&&(neg[i]-neg[pre-1])%2==0)
      {
         ans=two[i]-two[pre-1];
         x=pre-1,y=n-i;
      }
    }
    pre=n;
    for(int i=n;i>=1;i--)
    {
      if(a[i]==0)
      {
         pre=i-1;continue;
      }
      if(two[pre]-two[i-1]>ans&&(neg[pre]-neg[i-1])%2==0)
      {
         ans=two[pre]-two[i-1];
         x=i-1,y=n-pre;
      }
    }
    cout<<x<<" "<<y<<endl;
}