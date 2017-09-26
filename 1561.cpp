#include<stdio.h>
int main()
{
	int a,b,c,d=2,e=2,f=1,h=0;
	scanf("%d",&a);
	while(f!=a)
	{
		e=e+1;
		for(d=2;d*d<=e;d++)
		 {
		 c=e/d;
		 if(c*d==e) h=h+1;}
		 if(h==0) f=f+1;
		 h=0;
	}
	printf("%d\n",e);
	
	 
	 
	 
	
}
