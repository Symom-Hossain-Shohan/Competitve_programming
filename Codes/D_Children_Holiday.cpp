#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int M,n;
vector<int> t,z,y,ans;

bool good_ballon(int ballon,int pos,int Time)
{
    int batch_time=(t[pos]*z[pos])+y[pos];
    int no_of_batch=ballon/z[pos];
    bool ok = (ballon % z[pos] == 0) ? 1 : 0;
    int required_time=0;
    if(ok)
    {
        no_of_batch--;
        required_time=no_of_batch*batch_time+z[pos]*t[pos];
    }
    else 
    {
        required_time=no_of_batch*batch_time+(ballon%z[pos])*t[pos];
    }
    return required_time<=Time;
}

bool good_time(int Time)
{
    int total_ballon=0;
    for(int i=0;i<n;i++)
    {
        int l=0,r=(int)1e9;
        while(r>l+1)
        {
            int m=(l+r)/2;
            if(good_ballon(m,i,Time)) l=m;
            else r=m;
        }
        total_ballon+=l;
    }
    return total_ballon>=M;
}

int count_ans(int pos,int Total_time)
{
    int batch_time=(t[pos]*z[pos])+y[pos];
    int number_of_batches=Total_time/batch_time;
    int remaining_time=Total_time%batch_time;
    int ans=0;
    ans+=number_of_batches*z[pos];
    if(remaining_time)
    {
        if (remaining_time / t[pos] >= z[pos]) 
        {
			ans += z[pos];
		}
		else 
        {
			ans+= (remaining_time / t[pos]);
		}
    }
    return ans;
}

void solve()
{
    cin >> M >> n;
    t.resize(n),z.resize(n),y.resize(n);
    ans.resize(n,0);

    for(int i=0;i<n;i++) cin >> t[i] >> z[i] >> y[i];

    int l=-1,r=(int)1e9;

    while(r>l+1)
    {
        int m=(l+r)/2;
        if(good_time(m)) r=m;
        else l=m;
    }

    cout << r << endl;
    for(int i=0;i<n;i++) ans[i]= count_ans(i,r);
    int totalBalloons = 0;
	for (int i = 0; i < n; i++) {
		if (totalBalloons + ans[i] <= M) {
			cout << ans[i] << " ";
			totalBalloons += ans[i];
		}
		else {
			if (totalBalloons == M) {
				cout << 0 << " ";
			}
			else {
				cout << (M - totalBalloons) << " ";
				totalBalloons = M;
			}
		}
	}
	cout << endl;
}

int main()
{
    ll tc=1;
    //cin >> tc;
    for(ll t=1;t<=tc;t++)
    {
        solve();
    }
    return 0;
}