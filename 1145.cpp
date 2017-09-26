#include<stdio.h>
int main()
{
	int a[10005]={0};
	int b, c, d, e[100], i = 0,h = 0, g, f[100];
	scanf("%d %d", &b, &c);
    for(d = 0; d < c; d++) {
		scanf("%d %d", &e[d], &f[d]);
		for(g = e[d]; g <= f[d]; g++)
		a[g] = 1;
	}
	i = 0;
	for (i = 0; i <= b; i++ ) {
	if (a[i] != 1 )
	h = h+1; }	
	printf("%d\n",h);
}
