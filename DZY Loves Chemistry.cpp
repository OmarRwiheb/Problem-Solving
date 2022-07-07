//my solution for codeforces problem https://codeforces.com/contest/445/problem/B

#include<bits/stdc++.h>

using namespace std;

const int MX = 1e6 + 1;

#define PI 3.14159265
#define sqr(x) ((x)*(x))
#define pr pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define all(v) ((v).begin()), ((v).end())
#define rev(v) ((v).rbegin()), ((v).rend())
#define rep(i, st, en) for(int i = st; i < en; i++)
#define Fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b) { return a * b / gcd(a, b); }


bool sortbysec(const pair<string, string> &a, const pair<string, string> &b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;

}

template<typename T>
void input(vector<T> &v) { for (auto &it : v) cin >> it; }

ll binPow(ll b, ll p) {
    if (p == 0) return 1;
    ll sq = binPow(b, p / 2);
    sq *= sq;

    if (p & 1)
        sq *= b;

    return sq;
}

vector<vector<int>> adj;
vector<bool> vis;
ll ans = 1;

void dfs(int u) {
    vis[u] = 1;
    for (int neig: adj[u]) {
        if (vis[neig]) {
            continue;
        }
        ans *= 2;
        dfs(neig);
    }
}

int main() {
    Fast;

    int n, m;
    cin >> n >> m;
    adj.resize(n);
    vis.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if(!vis[i])
            dfs(i);
    }
    cout << ans;
    return 0;
}
