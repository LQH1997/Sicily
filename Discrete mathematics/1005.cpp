#include<iostream>
using namespace std;
int main() {
	int ifTrue = 0;
	int n, number, elementNumber;
	cin>>n;
	for(int i = 0; i < n; i++) {
		cin>>number;
	}
	cin>>elementNumber;
	int arr[elementNumber][2];
	for(int i = 0; i < elementNumber; i++) {
		cin>>arr[i][0]>>arr[i][1];
	}
	for(int i = 0; i < elementNumber; i++) {
		int a = arr[i][0];
		int b = arr[i][1];
		if(a != b) {
			ifTrue = 0;
		for(int q = 0; q < elementNumber; q++) {
			if(arr[q][0] == b && arr[q][1] == a)
			ifTrue += 1;
		}
		if(ifTrue == 0) {
			cout<<"0"<<endl;
			return 0;
		}
	}
	}
    cout<<"1"<<endl;
    return 0;
}
