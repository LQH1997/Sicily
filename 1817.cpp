#include<stdio.h>
int main() {
	int n,m,a,b,c,d,e,f,t,sum = 0;
	int arr[100][100];
	scanf("%d",&t);
	for(a = 0; a < t;a++) {
		scanf("%d %d",&n,&m);
		for(b = 0;b < n; b++) {
			for(c = 0; c < m;c++) {
				scanf("%d",&arr[b][c]);
			}
		} 
		for(d = 0;d < m;d++) {
		for(b = 0; b < n; b++) {
			for(c = 0;c <n-1;c++) {
				if(arr[c][d]>arr[c+1][d]) {
					e = arr[c+1][d];
					arr[c+1][d] = arr[c][d];
					arr[c][d] = e;
				}
			}
		}
		for(f = 1; f < n - 1; f++) {
			sum = sum + arr[f][d];
		}
		printf("%.2f\n",(double)sum/(n-2));
		sum = 0;
		
	}
}
}
