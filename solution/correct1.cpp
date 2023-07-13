#include <bits/stdc++.h>
#define ll long long
#define int long long
#define fi first
#define se second
#define mat vector<vector<ll>> 
using namespace std;
void db() {cout << '\n';}
template <typename T, typename ...U> void db(T a, U ...b) {cout << a << ' ', db(b...);}
#ifdef Cloud
#define file freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define file ios::sync_with_stdio(false); cin.tie(0)
#endif
struct seg{
    int l, r, mid, lz = -1, sum = 0;
    seg *ch[2]{};
    void push(){
        if (lz < 0) return;
        for (auto i : ch){
            i->sum = lz * (i->r - i->l + 1);
            i->lz = lz;
        }
        lz = -1;
    }
    void set(int _l, int _r, int val){
        if (_l <= l and _r >= r) {
            lz = val;
            sum = (r - l + 1) * val;
            return;
        }
        if (_l > r or _r < l) return;
        push();
        ch[0]->set(_l, _r, val);
        ch[1]->set(_l, _r, val);
        sum = ch[0]->sum + ch[1]->sum;
    }
    int query(int _l, int _r){
        if (_l <= l and _r >= r) return sum;
        if (_l > r or _r < l) return 0;
        push();
        return ch[0]->query(_l, _r) + ch[1]->query(_l, _r);
    }
    seg (int _l, int _r) : l(_l), r(_r), mid(l + r >> 1){
        if (l < r) ch[0] = new seg(l, mid), ch[1] = new seg(mid + 1, r);
    }
};
signed main(){
    file;
    int n, q;
    cin >> n >> q;
    int a[n], ans[q];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<pair<int, int>> v[n];
    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l--, r--;
        v[l].push_back({r, i});
    }
    vector<int> stk;
    seg *rt = new seg(0, n - 1);
    for (int i = n - 1; i >= 0; i--){
        while (!stk.empty() and a[stk.back()] > a[i]) stk.pop_back();
        int r = stk.empty() ? n - 1 : stk.back() - 1;
        stk.push_back(i);
        rt->set(i, r, a[i]);
        for (auto j : v[i]){
            ans[j.se] = rt->query(i, j.fi);
        }
    }
    for (int i : ans) cout << i << '\n';
    /*
    7 5
    2 3 1 4 7 2 5
    1 6
    5 7
    3 7
    2 4
    4 6
    */
}
