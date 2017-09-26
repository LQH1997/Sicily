#include<stdio.h>
#include<string.h>
int main() {
	int city, rode,i,a,b,c,d,e;
	int arr[200][200] = {0};
	scanf("%d",&city);
	while(city!=0) {
		scanf("%d",&rode);
		memset(arr,0,sizeof(arr));
		for(i = 0; i < rode; i++) {
			scanf("%d %d",&a,&b);
			arr[a][b] = 1;
		}
		for(i = 0; i < city; i++) {
			for(a = 0; a < city; a++) {
				if(arr[a][i] == 1) {
				   	for(d = 0; d < city; d++) {
				   		if(arr[i][d] == 1) {
				   			arr[a][d] = 1;
						   }
					   }
				}
			}
		}
		if(arr[0][city-1] == 1) {
			printf("I can post the letter\n");
		}
		else printf("I can't post the letter\n");
		scanf("%d",&city);
	}
}
