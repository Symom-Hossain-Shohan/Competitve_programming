#include<stdio.h>

int main()
{
    long long int ar[75];
    long long int n,m;
    scanf("%lld %lld",&n,&m);
    ar[0]=0;
    ar[1]=1;
    ar[2]=1;
    for(int i=3;i<75;i++)
    {
        ar[i]=ar[i-1]+ar[i-2];
    }
    long long int sum=0;
    for(int i=n;i<=m;i++) sum+=ar[i];
    printf("%lld\n",sum);
}