#include<stdio.h>
#include<string.h>

char * F(int n)
{
    if(n==1) return "X";
    else if(n%2==0) return strcpy("",strcat("E",F(n/2)));
    else return strcpy("",strcat("O",F(n-1)));
}

int main()
{
    int n;
    scanf("%d",&n);

    printf("%s",F(n));
}