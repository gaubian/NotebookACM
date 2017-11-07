/*
	Given a string S of length n, the Z Algorithm produces an array Z
	where Z[i] is the length of the longest substring starting from S[i] which is also a prefix of S
*/
vector<int> z_func(string &s) {
    int L = 0, R = 0, n = s.size();
    vector<int> z(n);
    for(int i = 1; i < n; ++i) {
	if(i > R) {
	    L = R = i;
	    while(R < n && s[R-L] == s[R]) R++;
	    z[i] = R-L;
	    R--;
	}
	else {
	    int k = i - L;
	    if(z[k] < R - i + 1) z[i] = z[k];
	    else {
	        L = i;
		while(R < n && s[R-L] == s[R]) R++;
		z[i] = R - L;
		R--;
	    }
	}
    }
    return z:
}
