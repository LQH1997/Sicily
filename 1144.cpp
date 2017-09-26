#include<stdio.h>
#include<string.h>
int main()
{
char a[500];
int b,c;
scanf("%s",&a);
b=strlen(a);
printf("%d\n",b);
for(c=b-1;c>=0;c--);
printf("%c",a[c]);
}
