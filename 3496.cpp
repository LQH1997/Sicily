#include<stdio.h>
int main()
{
	int a,b,e,f;
	float c,d;
	scanf("%d%d",&a,&b);
	while(a!=0&&b!=0)
	{
	c=2*a-b/2;
	f=c/1;
	d=b/2-a;
	e=d/1;
	if(c>=0&&d>=0&&f==c&&e==d)
	printf("%.0f %.0f\n",c,d);
	else printf("No answer\n");
	scanf("%d%d",&a,&b);
	}
	
	
}
