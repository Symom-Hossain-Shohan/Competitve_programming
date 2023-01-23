#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char num[n];
    scanf("%s",num);
    int i=0,a=0,b=0;
    for(i=0;i<n;i++)
    {
        if(num[i]=='1')
            a++;
        else
            b++;
    }
    if(a>b)
    printf("%d",n-b*2);
    else
        printf("%d",n-a*2);

}