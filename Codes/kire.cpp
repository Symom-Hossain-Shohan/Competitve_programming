#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
char ar[4][4];
long long p[6] ; 

char fun(int i, int j, int k)
{
	if(k==0) return ar[i][j] ; 
	else 
	{
		if(ar[i/p[k]][j/p[k]]=='*') return '*' ; 
		else return fun(i%p[k],j%p[k],k-1) ; 
	}
}

void solve()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout); 

	int n, k;
	cin >> n >> k ;
	 

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> ar[i][j] ; 
		}
	}
	p[0]=1 ; 
	
	for(int i=1;i<=k;i++)  p[i]=p[i-1]*n ; 

	//cout << p[k] << endl ; 

	for(int i=0;i<p[k];i++)
	{
		for(int j =0;j<p[k];j++)
		{
			cout << fun(i,j,k-1) ;
		}
		cout << endl; 
	}

}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	ll tc=1;
	//cin >> tc;
	for(ll t=1;t<=tc;t++)
	{
		solve();
	}
	return 0;
}