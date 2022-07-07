//my solution for codeforces problem https://codeforces.com/contest/1542/problem/B

#include<bits/stdc++.h>

using namespace std;

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


bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) { return a.second < b.second; }

template<typename T>
void takeInput(vector<T>& v){ for(auto& it : v) cin >> it; }

ll binPow(ll b, ll p) {
    if (p == 0) return 1;
    ll sq = binPow(b, p / 2);
    sq *= sq;

    if (p & 1)
        sq *= b;

    return sq;
}

int main() {
    Fast;

    int tc;
    cin >> tc;
    while(tc--){
        ll n, a, b;
        cin >> n >> a >> b;
        ll temp = 1;
        bool f = 0;
        while(temp <= n) {
            f |= abs(temp - n) % b == 0;
            temp *= a;
            if(a == 1 || f)break;
        }
        if(f)cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
