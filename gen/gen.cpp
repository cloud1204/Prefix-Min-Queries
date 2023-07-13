#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int MINN = 1;
int MAXN = 300'000;
int MAXA = 1e9;
int FIXR = 0;
int32_t main(int32_t argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    if (has_opt("minn")) MINN = opt<int>("minn");
    if (has_opt("maxn")) MAXN = opt<int>("maxn");
    if (has_opt("fixr")) FIXR = opt<int>("fixr");
    int n = rnd.next(MINN, MAXN);
    int q = MAXN;
    vector<int> a(n);
    string type = opt("type");
    
    for (int i = 0; i < n; i++){
    	a[i] = rnd.next(1, MAXA);
    }
    /// types ///
    if (type == "almost_sorted" or type == "max_case"){
    	sort(a.begin(), a.end());
    	reverse(a.begin(), a.end());
    	for (int i = 0; i < 10000; i++){
    	    int x = rnd.next(0, n - 2);
    	    int y = rnd.next(x + 1, min(n - 1, x + 100));
    	    swap(a[x], a[y]);
    	}
    }
    /// prints ///
    
    cout << n << ' ' << q << '\n';
    for (int i = 0; i < n; i++){
    	cout << a[i] << (i == n - 1 ? '\n' : ' ');	
    }
    for (int i = 0; i < q; i++){
    	int l = rnd.next(1, n);
    	int r = rnd.next(1, n);
    	if (type == "max_case"){
    	    l = rnd.next(1, 1000);
    	    r = rnd.next(n - 1000, n);
    	}
    	if (l > r) swap(l, r);
    	if (FIXR) r = n;
    	cout << l << ' ' << r << '\n';
    }
    return 0;
}
