//my solution for codeforces problem https://codeforces.com/contest/1538/problem/C

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
 
 
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
    return a.second < b.second;
}
 
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
        int n, l, r;
        cin >> n >> l >> r;
        vll v(n);
        takeInput(v);
        sort(all(v));

        auto count_below = [&](int cutoff){
            ll total = 0;
     
            for (int i = 0, j = n - 1; i < j; i++) {
                while (j > i && v[i] + v[j] > cutoff)
                    j--;
     
                total += max(j - i, 0);
            }
     
            return total;
        };
        
        cout << count_below(r) - count_below(l - 1) << '\n';
    }

    return 0;
}
 
