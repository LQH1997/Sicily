#include<iostream>
#include<string>
using namespace std;
int main() {
	int num;
	int arr[100][100];
	cin>>num;
	int i, q, t, a, d, b;
	for(i = 0; i < num; i++) {
		for(q = 0; q < num; q++) {
			cin>>arr[i][q];
		}
	}
	for(i = 0; i < num; i++) {
			for(a = 0; a < num ;a++) {
				if(arr[a][i] == 1) {
				   	for(d = 0; d < num; d++) {
				   		arr[a][d] = arr[a][d] | arr[i][d];
					   }
				}
			}
		}
	int testcase;
	string str;
	cin>>testcase;
	for(int z = 0; z < testcase; z++) {
		cin>>a>>b;
		if(arr[a][b] == 1) str += "1 ";
		else str+="0 ";
	}
	cout<<str<<endl;
}
