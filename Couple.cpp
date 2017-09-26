#include<stdio.h>
int main() {
int arr[50000];
int n = 0, a = 0, b = 0, c = 0, x = 0, y = 0;
int d = 0, z = 1;
int i = 1, x1 = 0, x2 = 0, x3 = 0, x4 = 0;
scanf("%d", &n);
while(n != 0) {
for (i = 1; i <= n; i++) {
scanf("%d %d", &a, &b);
if (a == (b + 1) || a == (b - 1)) {
arr[a] = 0;
arr[b] = 0;
} else {
arr[a] = arr[b] = i;
}
}
for(y = 1; y <= 10 * n; y++) {
for (c = 1; c <= 2 * n; c++) {
if (arr[c] == 0) continue;
i = c + 1;
while(arr[i] == 0) {
i = i + 1;
}
x1 = i;
if(arr[c] == arr[x1]) arr[c]=arr[x1]=0;
}}
for (d = 1; d <= 2 * n; d++) {
if (arr[d] != 0) x = x + 1;
}
if ( x == 0) { printf("Yes\n");
} else {
printf("No\n");
}
x = 0;
for (d = 1; d < 50000; d++) {
arr[d] = 0;
}
scanf("%d", &n);
}
}

