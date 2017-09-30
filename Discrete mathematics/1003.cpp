typedef set<int> Set;
typedef set<pair<int, int> > Relation;
bool transitive(const Relation &R, const Set &A) {
    int a,b,c,d = 0, e;
    set<pair<int, int> >::iterator it,iter,iter1;
    for(it = R.begin();it != R.end(); it++) {
    	a = it->first;
    	b = it->second;
    	if(a != b) {
    	for(iter = R.begin();iter != R.end();iter++) {
    		if(b == iter->first&&iter->first!=iter->second) {
    			c = iter->second;
    			d = 0;
    			for(iter1 = R.begin(); iter1 != R.end();iter1++) {
    				if(a == iter1->first&&c==iter1->second) {
    					d++; break;
					    }
				    }
				    if(d==0) return false;
			    }
		    }
	    }
    }
	return true;
}
