#include<stdio.h>
#include<string.h>
int main()
{
	int a,d,e;
	scanf("%d",&a);
	int b;
	char c[80];
	for(d=0;d<a;d++)
	{
	
	scanf("%d%s",&b,&c);
printf("%d ",d+1);
	for(e=0;e<b-1;e++)
	{printf("%c",c[e]);}
	e=e+1;
for(;e<strlen(c);e++)
{printf("%c",c[e]);	}
printf("\n");
e=0;	
}
}
