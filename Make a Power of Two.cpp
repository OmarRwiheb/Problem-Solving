//my soution for codeforces problem https://codeforces.com/contest/1560/problem/D

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

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
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;

}

template<typename T>
void input(vector<T>& v){ for(auto& it : v) cin >> it; }

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
    vector<ll> powers;
    ll j = 1;
    while (j <= 1e18) {
        powers.push_back(j);
        j *= 2;
    }

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = INT_MAX;
        for (int i = 0; i < powers.size(); i++) {
            int dif = 0;
            int pos = 0, cnt = 0;
            string curpow = to_string(powers[i]);
            for (int x = 0; x < curpow.size(); x++) {
                int tmp = pos;
                for (int k = pos; k < s.length(); k++) {
                    if (curpow[x] == s[k]) {
                        pos = k + 1;
                        cnt++;
                        break;
                    }
                }
                if (pos == tmp) {
                    break;
                }
            }
            dif = (int) s.length() + (int) curpow.size() - (2 * cnt);
            ans = min(dif, ans);
        }

        cout << ans << '\n';
    }

    return 0;
}
