#include<iostream>
#include<vector>
using namespace std;
typedef set<int> Set;
typedef set<pair<int, int> > Relation;
bool reflexive(const Relation &R, const Set &A) {
    int n = A.size(), count = 0;
    set<pair<int, int> >::iterator it;
    for (it = R.begin(); it != R.end(); it++) {
        if (it->first == it->second) count++;
    }
    if (count == n) return true;
    else return false;
}
int main() {
	bool Q;
	relation a;
	set A = <pair<1,1>,pair<1,2>>;
	Q = reflexive(a,A);
	if(Q == true) cout<<"Y";
	else cout<<"N";
}
