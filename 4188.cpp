#include<stdio.h>

int main()
{
	int a=2;
	int b,c,d,n,i1,i2=0,e[20],j;
	scanf("%d",&n);
	for(i1=0;i1<n;i1++)
	{
	scanf("%d",&b);
	do{
	c=b/a;
	d=b%a;
	b=c;
	i2=i2+1;
	e[i2]=d;}
	while(c!=0);
	for(j=i2;j>0;j--)
	printf("%d",e[j]);
	printf("\n");
	i2=0;}
	
}
