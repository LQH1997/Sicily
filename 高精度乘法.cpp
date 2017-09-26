#include<stdio.h>
#include<string.h>
int main()
{
char n[1000]={},m[1000]={};
int n1[1000]={},m1[1000]={},s[1000]={};
int i,j,k=0,t,x=0,dig,p = 0,r1 = 0,r2 = 0;
int lenn,lenm;
int a;
scanf("%d",&a);
while(a--) {
scanf("%s%s",n,m);
lenn=strlen(n);
lenm=strlen(m);
for(p = 0;p<lenn;p++) {
	if(n[p]=='0') r1 = r1 + 1;
}for(p = 0;p<lenm;p++) {
	if(m[p]=='0') r2 = r2 + 1;
}
if(r1 == lenn||r2 == lenm) {
	printf("0\n");
} else {
for(i=0;i<lenn;i++)
n1[i]=n[i]-48;
for(j=0;j<lenm;j++)
m1[j]=m[j]-48;
for(j=lenm-1;j>=0;j--)
{
t=k;
for(i=lenn-1;i>=0;i--)
{
s[t]+=n1[i]*m1[j];
t++;
}
++k;
dig=t;
}
for(i=0;i<dig;i++)
if(s[i]>=10)
{
s[i+1] += s[i] / 10;
s[i] = s[i] % 10;
}
while(s[dig]==0) {
	dig--;
}
for(i=dig;i>=0;i--)
printf("%d",s[i]);
   printf("\n");
   for(i = 0; i <= dig; i++) {
   	s[i] = n1[i] = m1[i] = 0;
   }
}
memset(m,0,sizeof(m));
memset(n,0,sizeof(n));
i = 0;j = 0;k=0;t = 0;x=0;dig = 0;
lenn = 0;lenm = 0; p = 0; r2 = 0; r1 = 0;
}return 0;}
