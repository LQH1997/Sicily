#include<stdio.h>
int main() {
	int a[100][100]={0}, b = 0,  hang = 0, lie = 0, k = 1;
	int m = 1, n = 1, z = 1;
	scanf("%d",&b);
	for (lie=1;lie<=b;lie++) {
		for (hang=1;hang<=b;hang++) {
			a[lie][hang] = k;
			k = k + 1;
		}
	}
	printf("%d ",a[n][m]);
	m = m + 1;
	do{
		if ((m+n)%2!=0) {
			do {
				printf("%d ",a[n][m]);
				m = m - 1;
				n = n + 1;
				z = z + 1;
				if ((z%b)==0) printf("\n");
			} while(m>=1&&n<=b);
			m = m + 1; n = n - 1;
			if (n<b) n = n + 1;
			else m = m + 1;
	}
	else {
		do { 
			printf("%d ",a[n][m]);
			m = m + 1;
			n = n - 1;
            z = z + 1;
            if ((z%b)==0) printf("\n");
		} while(n>=1&&m<=b);
		m = m - 1;
		n = n + 1;

		if (m<b) m = m + 1;
		else n = n + 1;
	}
} while((m+n)<=2*b);
}
