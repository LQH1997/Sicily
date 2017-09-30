#include<iostream>
using namespace std;
int main() {
	int judge = 0;
	int n;
	cin>>n;
	int number;
	for(int i = 0; i < n; i++) {
		cin>>number;
	}
	int rElementNumber;
	cin>>rElementNumber;
	for(int i = 0; i <rElementNumber; i++) {
		int a, b;
		cin>>a>>b;
		if(a == b) judge += 1;
	}
	if(judge == n) cout<<"1"<<endl;
	else cout<<"0"<<endl;
}
