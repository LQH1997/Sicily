#include<stdio.h>
int main()
{
	int a,b,f;
	int i,c,d = 0;
	scanf("%d", &b);
	for(f = 0; f < b; f++) {
	scanf("%d",&a);
	if(a == 0 || a == 1)
	printf("No\n");
	else{	
	for( i = 2; i*i <= a; i++)
	{c = a/i; if( i*c == a) d = d+1;}
	if(d > 0) printf("No\n");
	else printf("Yes\n");
	}
	d = 0;
   }

}
	

