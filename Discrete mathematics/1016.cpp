#include<iostream>
using namespace std;
int main() {
	int num, n, arr[100][100];
	int ifTrue = 0;
	cin>>num;
	for(int i = 0; i < num; i++) {
		cin>>n;
		for(int t = 0; t < n; t++) {
			for(int q = 0; q < n; q++) {
				cin>>arr[t][q];
			}
		}
		ifTrue = 0;
		for(int z = 0; z < n; z++) {
			if(arr[z][z] == 0) {
                ifTrue = 1;
			}
			}
			if(ifTrue == 1) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
	}

