#include <iostream>
using namespace std;
int main() {
	unsigned long long a, b = 1, c;
	cin>>a;
	for(; a >= 1; a--) {
		b *= a;
	}
	cout<<b<<endl;
}
