#include <bits/stdc++.h>
using  namespace std;

typedef long long ll;

int main()
{
	ll tc;
	cin >> tc;
	while(tc--)
	{
		ll n;
		cin >> n;
		vector<ll> v(n+2),neg(n+2,0),tow(n+2,0);
		for(int i=1;i<=n;i++)
		{
			cin >> v[i];
			neg[i]+=neg[i-1];
			tow[i]+=tow[i-1];
			if(v[i]<0) neg[i]++;
			if(v[i]==2 or v[i]==-2) tow[i]++;
		}

		ll lf=n,rf=0,last=1,ans=-1;
		for(int i=1;i<=n;i++)
		{
			if(v[i]==0) 
			{
				last=i+1;
				continue;
			}
			if(tow[i]-tow[last-1]>ans and (neg[i]-neg[last-1])%2==0) 
			{
				ans=tow[i]-tow[last-1];
				lf=last-1;
				rf=(n-i);
			}

		}
		last=n;
		for(int i=n;i>=1;i--)
		{
			if(v[i]==0)
			{
				last=i-1;
				continue;
			}
			if(tow[last]-tow[i-1]>ans and (neg[last]-neg[i-1])%2==0)
			{
				ans=tow[last]-tow[i-1];
				lf=i-1;
				rf=n-last;
			}
		}
		cout << lf << ' ' << rf << endl;
	}
}