#include<stdio.h>
int main() {
char arr[100][100];
int a,b = 0,c = 0,d = 1,e;
char f[1];
while(scanf("%d",&a)!=EOF) {
f[0] = getchar();
while(scanf("%c", &arr[c][b]) && arr[c][b] != '\n') {
if(d % 2 != 0) b = b + 1;
if (d % 2 == 0) b = b - 1;
if (b == a) {
b = a - 1;
d = d + 1;
c = c + 1;
}
if (b == -1) {
b = 0;
d = d + 1;
c = c + 1;
}
}
for(b = 0; b < a; b++) {
for (c = 0; c < d; c++ ) {
//if( arr[c][b] >= 97 && arr[c][b] <= 122) 
printf("%c", arr[c][b]);
}
}
printf("\n");
/*for(b = 0; b < a; b++) {
for (c = 0; c < d; c++ ) {
arr[c][b] = '0';
}
}*/
b = c = 0;
d = 1;
}
}

