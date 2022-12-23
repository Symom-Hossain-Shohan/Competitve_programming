#include<stdio.h>


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    int dept[m+1];
    for(int i=0;i<=m;i++) dept[i]=0;
    for(int i=0;i<n;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        dept[u]+=v;
    }
    int ar[m+1];
    for(int i=1;i<=m;i++) ar[i]=dept[i];

    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<m+1-i;j++)
        {
            if(ar[j]<ar[j+1])
            {
                int t=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=t;
            }
        }
    }

    
    
    int marks[m+1];

    marks[1]=ar[1];
    int j=1;
    for(int i=1;i<=m;i++) 
    {
        if(ar[i]!=marks[j])
        {
            j++;
            marks[j]=ar[i];
        }
    }

   
   
    int rank[m+1];


    for(int i=1;i<=j;i++)
    {
        for(int k=1;k<=m;k++)
        {
            if(dept[k]==marks[i]) rank[k]=i;
        }
    }

    for(int i=1;i<=m;i++) printf("%d\n",rank[i]);
    

    
}