#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=300005;
ll a[MAXN],b[MAXN];
ll sum[MAXN];
int main()
{
	int n;
	cin >> n;
	for (int i=1;i<=n;++i) cin >> a[i];
	for (int i=1;i<=n;++i) cin >> b[i];
	sum[n] = a[n]+b[n];
	for (int i=n-1;i>0;--i) sum[i] = sum[i+1]+a[i]+b[i];
	ll ab=0,ba=0,aend=0,bend=0;
	for (int i=n;i>0;--i)
	{
		ll nab = a[i]+ab+sum[i+1]+b[i]*2*(n-i+1);
		ll nba = b[i]+ba+sum[i+1]+a[i]*2*(n-i+1);
		ll naend= a[i]+2*b[i]+max(bend,ba)+sum[i+1]*2;
		ll nbend= b[i]+2*a[i]+max(aend,ab)+sum[i+1]*2;
		ab=nab,ba=nba,aend=naend,bend=nbend;
	}
	cout << max(ab,aend)-sum[1] << endl;
}