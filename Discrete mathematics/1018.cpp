#include<iostream>
using namespace std;
int main() {
	int num, n, i, t, q;
	int arr[100][100];
	bool ifTrue = true;
	cin>>num;
	for(i = 0; i < num; i++) {
		cin>>n;
		ifTrue =  true;
		for(t = 0; t < n; t++) {
			for(q = 0; q < n; q++) {
				cin>>arr[t][q];
			}
		}
		for(t = 0; t < n; t++) {
			for(q = 0; q < n; q++) {
				if(t != q) {
					if(arr[t][q] == 1) {
						if(arr[q][t] == 1) {
							ifTrue = false;
						}
					}
				}
			}
		}
	if(ifTrue) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;	
	}
}
