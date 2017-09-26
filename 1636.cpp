#include<stdio.h>
int main()
{
	int a,b=0,money,kind,cost[10],num[10],i,allcost=0,left;
	scanf("%d",&a);
	for(b=0;b<a;b++)
	{
		scanf("%d%d",&money,&kind);
		 for(i=0;i<kind;i++)
		  {scanf("%d%d",&cost[i],&num[i]);}
		 for(i=0;i<kind;i++)
		  {allcost=allcost+cost[i]*num[i];}
		  left=money-allcost;
		  if(left>=0) printf("%d\n",left);
		  else printf("Not enough\n");
		  allcost=0;
		  
		  
		
	}
	
	
}
