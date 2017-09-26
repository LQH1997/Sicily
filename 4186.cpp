#include<stdio.h>
int main(){
int a;
int b=3;
int i;
int c[10000],d[10000],e[10000];
scanf("%d",&a);
while(a!=0)
{
for(i=0;i<a*a;i++)
{scanf("%d",&c[i]);}
for(i=0;i<a*a;i++)
{scanf("%d",&d[i]);}

for(i=0;i<a*a;i++)
{e[i]=c[i]+d[i];}


for(i=0;i<a*a;i++)
{printf("%d",e[i]);if((i+1)%a!=0) printf(" "); else printf("\n");}
scanf("%d",&a);
}
}
	

	

	
	
