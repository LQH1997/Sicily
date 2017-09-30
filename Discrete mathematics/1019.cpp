#include<iostream>
using namespace std;
int main() {
	int num, n, i, t, q;
	int arr[100][100];
	bool ifTrue = true;
	cin>>num;
	for(i = 0; i < num; i++) {
		cin>>n;
		ifTrue = true;
		for(t = 0; t < n; t++) {
			for(q = 0; q < n; q++) {
				cin>>arr[t][q];
			}
		}
		for(t = 0; t < n; t++) {
			for(q = 0; q < n; q++) {
				if(arr[t][q] == 1) {
					for(int z = 0; z < n; z++) {
						if(arr[q][z] == 1) {
							if(arr[t][z] != 1) {
								ifTrue = false;
								break;
							}
						}
					}
				}
			}
		}
		if(ifTrue) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
