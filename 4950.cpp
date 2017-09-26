#include<stdio.h>
int main()
{
int a[2],b[2],c[2];
int i=0,d,e,f;
for(i=0;i<=2;i++)
scanf("%d",&a[i]);
for(i=0;i<=2;i++)
scanf("%d",&b[i]);
for(i=0;i<=2;i++)
scanf("%d",&c[i]);
d=a[0]*a[1]*a[2];
e=b[0]*b[1]*b[2];
f=c[0]*c[1]*c[2];
printf("%d\n%d\n%d\n",d,e,f);
}

