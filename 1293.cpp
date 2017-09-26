#include<stdio.h>
int main()
{
int a;
int b;
int c;
int d;
int e=1;
int f=0;
scanf("%d%d",&a,&b);
c=a;
for(;c<=b;c++)
{
e=1;
d=c;
while(d!=1)
{
if(d%2!=0) d=3*d+1;
else {d=d/2;};
e=e+1;
}
if(e>f) f=e;
else f=f;

}
printf("%d",f);
}











