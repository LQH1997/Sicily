#include<stdio.h>
int main()
{
int n,k;
int c=0,d=1,f=1,g=0;
scanf("%d%d",&n,&k);
for(;d<=k%9900;d++)
{
g=(g+1)*n;
g=g%9901;
}

printf("%d\n",g%9901);
}
