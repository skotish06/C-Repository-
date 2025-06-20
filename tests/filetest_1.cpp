#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d,x) memset(d, x, sizeof(d))
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define pb push_back
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s" << '\n';
#define shouko 1
#define orz shouko
#define task ""

using namespace std;
const int N = 1e6 + 9;
const int baseVal = 256;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;

int base1[N], base2[N];
int pre1[N], pre2[N];

int add(int a, int b, int mod) { return (a + b) % mod; }
int sub(int a, int b, int mod) { return ((a - b) % mod + mod) % mod; }
int mul(int a, int b, int mod) { return (a * b) % mod; }

ii getHash(int l, int r) {
    if (l > r) return {-1, -1};
    int h1 = sub(pre1[r], mul(pre1[l - 1], base1[r - l + 1], mod1), mod1);
    int h2 = sub(pre2[r], mul(pre2[l - 1], base2[r - l + 1], mod2), mod2);
    return {h1, h2};
}

void logic() {
    string a, b; cin >> a >> b;
    int n = a.size();
    int m = b.size();
    a = ' ' + a;
    b = ' ' + b;

    ii H = {0, 0};
    for (int i = 1; i <= m; ++i) {
        H.fi = add(mul(H.fi, baseVal, mod1), b[i], mod1);
        H.se = add(mul(H.se, baseVal, mod2), b[i], mod2);
    }

    base1[0] = base2[0] = 1;
    for (int i = 1; i <= max(n, m); ++i) {
        base1[i] = mul(base1[i - 1], baseVal, mod1);
        base2[i] = mul(base2[i - 1], baseVal, mod2);
    }

    for (int i = 1; i <= n; ++i) {
        pre1[i] = add(mul(pre1[i - 1], baseVal, mod1), a[i], mod1);
        pre2[i] = add(mul(pre2[i - 1], baseVal, mod2), a[i], mod2);
    }

    for (int r = m; r <= n; ++r) {
        int l = r - m + 1;
        if (getHash(l, r) == H) {
            cout << l << ' ';
        }
    }

    // execute;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    logic();
    return 0;
}
