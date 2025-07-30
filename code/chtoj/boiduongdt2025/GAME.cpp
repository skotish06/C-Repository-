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
// dont copy my flow dude
#define task ""


using namespace std;
const int N = 1e3 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n;
int dist[N][N];
int a[N][N];
int m;

struct Cell {
    int c, x, y;
    bool operator<(const Cell &other) const {
        return c > other.c;
    }
};

void dijk(ii start) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dist[i][j] = inf;

    priority_queue<Cell> pq;
    dist[start.fi][start.se] = a[start.fi][start.se];
    pq.push({dist[start.fi][start.se], start.fi, start.se});

    while (!pq.empty()) {
        Cell t = pq.top(); pq.pop();
        int c = t.c, x = t.x, y = t.y;

        if (c > dist[x][y]) continue;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                int ncost = max(c, a[nx][ny]);
                if (ncost < dist[nx][ny]) {
                    dist[nx][ny] = ncost;
                    pq.push({ncost, nx, ny});
                }
            }
        }
    }
}

void logic() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    while (m--) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        dijk({x, y});
        cout << dist[u][v] << '\n';
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
    
    // freopen(task ".inp", "r", stdin);
    // freopen(task ".out", "w", stdout);

    logic();

    return 0;
}

/*
--/shouko\--
DRAFT:


------------
*/