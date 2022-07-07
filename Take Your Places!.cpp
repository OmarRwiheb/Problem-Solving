//my solution for codeforces problem https://codeforces.com/contest/1556/problem/B

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
 
int main() {
    Fast;
 
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vll v(n);
        vll o(n);
        vll e(n);
        ll even = 0, odd = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            v[i] %= 2;
            if (v[i] & 1)odd++;
            else even++;
        }
        if (abs(even - odd) >= 2) {
            cout << "-1\n";
            continue;
        }
        auto simulate = [&](int p) -> ll {
            ll result = 0;
            ll curr = 0;
            for(int i = 0; i < n; i++){
                if(v[i] == p){
                    result += abs(i - curr);
                    curr += 2;
                }
            }
            return result;
        };
        ll cnt = -1;
        if(even == odd)cnt = min(simulate(0), simulate(1));
        else if(even > odd)cnt = simulate(0);
        else cnt = simulate(1);
        cout << cnt << "\n";
    }
    return 0;
}
