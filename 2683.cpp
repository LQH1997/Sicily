#include<stdio.h>
int main()
{
int a,b;
scanf("%d",&a);
while(a!=0)
{
b=a*a;
if (b%2==0) printf("Alice\n");
else printf("Bob\n");
scanf("%d",&a);
}
	

}
