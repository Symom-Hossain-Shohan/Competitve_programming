#include<stdio.h>

int main()
{
    char st[1005];

    int n;
    scanf("%d",&n);
    scanf("%s",st);
    int ans=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(st[i]=='0') cnt++;
        else 
        {
            if(ans<cnt) ans=cnt;
            cnt=0;
        }
    }
    if(ans<cnt) ans=cnt;
    printf("%d",ans);
}