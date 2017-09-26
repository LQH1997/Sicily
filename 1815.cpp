#include<stdio.h>
#include<math.h>
int main()
{
    int n,x=0;
    double a,b,c,d,z,y;
    scanf("%d",&n);
    for(;x<n;x++)
    {
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    y=(a-c)*(a-c)+(b-d)*(b-d);
    z=sqrt(y);
    printf("%.2lf\n",z);}
}
