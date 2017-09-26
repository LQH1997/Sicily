#include<stdio.h>

int main()

{int a,b,c;

int jieguo;

scanf("%d%d%d",&a,&b,&c);

jieguo=a;

for(int i=0;i<b-1;i++)

{

jieguo*=a%c;

jieguo%=c;

}

printf("%d\n",jieguo);

return 0;

}
