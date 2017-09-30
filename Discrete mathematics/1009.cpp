#include<iostream>
#include<cstring>
using namespace std;
bool sudoku(int g[9][9]) {
	int i = 0, j = 0, k = 0;
	int ifTrue = 0;
	int arr[10] = {0};
	for(i = 0; i < 9; i++) {
		//if(ifTrue == 1) break;
		memset(arr,0,sizeof(arr));
		for(j = 0; j < 9; j++) {
			arr[g[i][j]] += 1;
			if(arr[g[i][j]] >= 2) {
				ifTrue += 1;
				//break;
			}
		}
	}
	for(i = 0; i < 9; i++) {
		memset(arr,0,sizeof(arr));
		if(ifTrue != 0) break;
		for(j = 0; j < 9; j++) {
			if(g[j][i] > 10 || g[j][i] <= 0) ifTrue += 1;
			else (arr[g[j][i]] += 1);
			if(arr[g[j][i]] >= 2) ifTrue += 1;
		}
	}
	i = 0;
	j = 0;
	memset(arr,0,sizeof(arr));
	int count = 0;
while(count < 9) {
    	arr[g[i+3*(count/3)][j]] += 1;
    	if(arr[g[i+3*(count/3)][j]] >= 2) ifTrue += 1;
    	j++;
    	//count++;
    	if(j % 3 == 0&&j>0) {
    		j -= 3;
    		i += 1;
		}
		if(i % 3 == 0&&i>0) {
			count++;
			memset(arr,0,sizeof(arr));
			if(count % 3 == 0) {
			j = 0;
			i = 0;
		} else {
			i -= 3;
			j += 3;
		}
		}
	}
	if(ifTrue == 0) return true;
	else return false;
}
int main() {
	int arr[9][9];
	int i = 0, j = 0;
	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++) {
			cin>>arr[i][j];
		}
	}
	if(sudoku(arr)) cout<<"yes"<<endl;
	else cout<<"no";
}
