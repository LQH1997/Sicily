//输入n,代表n*n方阵，从右上角开始输出
// 找临界点，也就是转向的位置，用循环解决问题 
#include<stdio.h>
int main() {
int arr[100][100] = {0};
int x = 0, y = 0, m = 0, n = 0, i = 0;
int k = 1, d = 0;
int q = 0, w = 0;
scanf("%d", &n);
for(i = 1; i <= 2 * n - 1; i++) {
d = n + 1 - i;
x = d; y = i;
while(y <= d) {
arr[y][x] = k;
k = k + 1;
y = y + 1;
}
y= y - 1;
x = x - 1;
while(x >= i) {
arr[y][x] = k;
x = x - 1;
k = k + 1;
}
x = x + 1;
y = y - 1;
while(y >= i) {
arr[y][x] = k;
y = y - 1;
k = k + 1;
}
y = y + 1; x = x + 1;
while (x <= d-1) {
arr[y][x] = k;
x = x + 1;
k = k + 1;
}
}
for (q = 1; q <= n-1; q++) {
for (w = 1; w <= n; w++) {
printf("%d", arr[q][w]);
if (w == n) printf("\n");
else printf(" ");
}
}
for(w = 1; w <= n-1; w++) {
printf("%d ", arr[n][w]);
}
printf("%d", arr[n][n]);
}

