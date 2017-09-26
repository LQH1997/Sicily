#include <iostream>
using namespace std;
int main() {
	while(true) {
	unsigned long long a,b,c = 1,d,e,f = 1,g = 1;
	cin>>a>>b;
	d = a;
	e = b;
	for(; d > a - b; d--) {
		c *= d;
	}
	for(; e >=1; e--) {
		f *= e;
	}
	cout<< c / f<<endl;
}
} 
