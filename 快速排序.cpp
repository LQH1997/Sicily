#include<stdio.h>
void balabala(int a[],int n);
int m =0, n = 0;
int main() {
	int total;
	int a[100],z,y;
	scanf("%d",&total);
	y = total;
	for(z = 0;z<total;z++) {
		scanf("%d",&a[z]);
	}
	balabala(a,total);//ִ�п�������  totalΪ�ܹ���������ֵĸ��� 
	for(z=0;z<y;z++) {
		printf("%d ",a[z]);
	}
}
void balabala(int a[],int n) { //a[]Ϊ���ǵ����� n�������Ƿ��ص��ܹ�Ҫ��������ֵĸ��� 
	int i = 0;
	int j = n - 1;
	int c = a[0];
	if (n > 1) {
	while(i!=j) {
	while(j>0&&a[j]>=c&&j>i) {
		j--;
	}
	//c = a[i];
	a[i] = a[j];
	a[j] = c; 
	while(i<n&&a[i]<c&&i<j) {
		i++;
	}
	//c = a[j];
	a[j] = a[i];
	a[i] = c;
	}
	balabala(a,i);
	balabala(a+1+i,n - i - 1);
}
	
}
