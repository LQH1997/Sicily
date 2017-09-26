#include<stdio.h>
int main()
{
	long a,b=2,c,d,e,f=0,x,y,z,h;
	scanf("%u",&a);
	while(a!=0)
	   {c=a;
	   	do
	  {
	    f=0;
	   	for(b=2;b*b<=c;b++)
	   	{
		d=c/b;
	   	if(b*d==c) f=f+1;
	    }
	    c=c-1;
	  }while(f!=0);
	  x=c+1;

	   z=a;f=0;
	  	do
	  {
	    f=0;
	   	for(h=2;h*h<=z;h++)
	   	{
		d=z/h;
	   	if(h*d==z) f=f+1;
	    }
	    z=z+1;
	  }while(f!=0);
	  y=z-1;

printf("%u\n",y-x);
	  scanf("%u",&a);
	  
	  
	  
}
}
