#include "testlib.h"

#include <bits/stdc++.h>
using namespace std;

int MINN = 1;
int MAXN = 300'000;
int MINQ = 1;
int MAXQ = 300'000;
int MAXA = 1e9;

int32_t main(int32_t argc, char* argv[]) {
    registerValidation(argc, argv);
    
    /// start input ///
    
    int n = inf.readInt(MINN, MAXN, "n");
    inf.readSpace();
    int q = inf.readInt(MINQ, MAXQ, "q");
    inf.readEoln();
    int a[n];
    for (int i = 0; i < n; i++){
    	a[i] = inf.readInt(1, MAXA, "a_i");
    	if (i < n - 1) inf.readSpace();
    	
    }
    inf.readEoln();
    for (int i = 0; i < q; i++){
    	int l = inf.readInt(1, n, "l");
	inf.readSpace();
	int r = inf.readInt(l, n, "r");
	inf.readEoln();
    }
    inf.readEof();
    
    return 0;
}
