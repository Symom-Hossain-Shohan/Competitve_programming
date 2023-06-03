#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define F first
#define S second
#define INF INT_MAX

#define ALL(x) (x).begin(), (x).end()
#define DBG(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << endl



const int nmax = 1e3+7;
const LL LINF = 1e17;


int ara[nmax];
int n,k;

bool isPossible(int d)
{
    int sum = 0;
    int cnt = 0;

    for(int i=1; i<=n; i++)
    {
        if(d<ara[i])
            return false;

        if(sum+ara[i]<=d)
            sum += ara[i];
        else
            cnt++, sum = ara[i];
    }

//  cout<<d<<" : "<<cnt<<endl;
    cnt++;
    return cnt<=k;
}

void printAns(int d)
{
    int sum = 0;
    int cnt = 0;

    for(int i=1; i<=n; i++)
    {
        if(sum+ara[i]<=d)
            sum += ara[i];
        else
        {
//            cout<<sum<<endl;
            printf("%d\n",sum);
            cnt++;
            sum = ara[i];
        }

        if(n-i+1==k-cnt)
        {
            printf("%d\n",sum);

            for(int j=i+1;j<=n;j++)
                printf("%d\n",ara[j]);

            break;
        }
    }
}

int main()
{
    int tc;
    scanf("%d",&tc);

    for(int q=1; q<=tc; q++)
    {
        scanf("%d %d",&n,&k);
        n++, k++;

        int lo = 0, hi = 0, mid = 0;

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&ara[i]);

            lo = max(lo,ara[i]);
            hi += ara[i];
        }

        int ans = lo;

        while(lo<hi)
        {
            mid = (lo+hi)/2;

            //DBG(lo) , DBG(hi) , DBG(mid);

            if(isPossible(mid))
                hi = mid, ans = mid;
            else
                lo = mid+1;
        }

        //        cout<<"Case "<<q<<": "<<ans<<endl;
        printf("Case %d: %d\n",q,ans);

        printAns(ans);

    }


    return 0;
}


