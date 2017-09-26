#include<stdio.h>
int main()
{
	int a,b[100],i;
	scanf("%d",&a);
	while(a!=0)
	 {
	 for(i=0;i<a;i++)
	  scanf("%d",&b[i]);
	for(i=0;i<a;i++)
	 {
	 if(b[i]>=b[i+1])  b[i+1]=b[i];
	 else b[i+1]=b[i+1];
     }
     printf("%d\n",b[a-1]);
     scanf("%d",&a);
    }
	  
}
