#include<stdio.h>


int main()
{
    int n;
    scanf("%d",&n);
    int ar[n];
    for(int i=0;i<n;i++) scanf("%d",&ar[i]);

    int ans=0;
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(ar[j]>ar[j+1])
            {
                int t=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=t;
            }
        }
    }

    int v=ar[0];
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(ar[i]==v) cnt++;
        else 
        {
            ans+=(cnt-1);
           // printf("%d %d\n",ans,i);
            v=ar[i];
            cnt=1;
        }
    }
    ans+=cnt-1;


    printf("%d\n",ans);
}