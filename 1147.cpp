#include<stdio.h>
#include<string.h>
int main()
{
  
    int i=0,loop=0,num=0,money=0,total=0,all=0,FinalExam=0,ClassJudge=0;
    char a[25],name[25]="0000",c,d;

scanf("%d",&loop);
for(i=0;i<loop;i++)
{
    scanf("%s %d %d %c %c %d",a,&FinalExam,&ClassJudge,&c,&d,&num);
    if(FinalExam>80&&num>=1)
    {money=money+8000;}
  if(FinalExam>85&&ClassJudge>80)
    money=money+4000;
    if(FinalExam>90)
    money=money+2000;
    if (FinalExam>85&& d=='Y')
    money= money+1000;
   if (ClassJudge>80&& c=='Y')
    money=money+850;
   if(all<money) {all=money; strcpy(name,a);}
    total+=money;
    money=0;}
    printf("%s\n%d\n%d\n",name,all,total);

}
    	


 

