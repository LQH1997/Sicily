1002
typedef set<int> Set;
typedef set<pair<int, int> > Relation;
bool antisymmetric(const Relation &R, const Set &A) {
    int find;
    set<pair<int, int> >::iterator it, iter;
    for (it = R.begin(); it != R.end(); it++) {
        int m = it->first, n = it->second;
        find = 0;
        for (iter = R.begin(); iter != R.end(); iter++) {
            if (m == iter->second && n == iter->first && m != n) {
                return false;
            }
        }
    }
    return true;
}     
