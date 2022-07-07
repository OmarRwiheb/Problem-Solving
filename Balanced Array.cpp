//my solution for codeforces problem https://codeforces.com/contest/1343/problem/B

#include<bits/stdc++.h>

using namespace std;

#define PI 3.14159265
#define sqr(x) ((x)*(x))
#define vi vector<int>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define all(v) ((v).begin()), ((v).end())
#define rev(v) ((v).rbegin()), ((v).rend())
#define rep(i, st, en) for(int i = st; i < en; i++)
#define Fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long int ulli;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }


bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
    return a.second < b.second;
}

template<typename T>
void takeInput(vector<T>& v){
    for(auto& it : v)
        cin >> it;
}

int main() {
    Fast
    
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        if((n / 2) % 2){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";

        for(int i = 2; i <= n; i+=2){
            cout << i << " ";
        }
        for(int i = 1; i <= n + 1; i+=2){
            if(i == (n / 2 + 1))continue;
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}
