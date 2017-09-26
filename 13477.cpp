#include<stdio.h>
int main()
{
	int a,b,c,d;
	scanf("%d",&a);
	if (a==1) printf("1\n");
	else 
	{ printf("1\n");
		for(b=2;b<=a;b++)
		{
		 for(c=1;c<=b;c++)
		 {printf("%d ",c);}
		
		 for(d=c-2;d>1;d--)
		 {printf("%d ",d);}
		 printf("1\n");
		 c=1;
		 
		}
	}
}
