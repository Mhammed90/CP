#include <bits/stdc++.h>
//
#pragma GCC optimize("O3", "unroll-loops", "Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll                 long long
#define all(v)             v.begin(),v.end()
#define  el   "\n"
#define clr(v, val) memset(v,val,sizeof(v));
#define debug(x)  cout<<#x<<" "<<x<<el;
const int Mod = 1e9 + 7;
const int Oo = 0x3F3F3F3F;
const int N = 10000069;
const int Inf = 1e9 + 7;
#define  int long long

void fast() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int dx[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dy[] = {-1, 1, 0, 0, 1, 1, -1, -1};

vector<bool> Prime(2400000+100);
void Sieve() {

    Prime[0] = Prime[1] = true;
    for (int i = 2; i <2400000+20; i++) {
        if (Prime[i] == 0) {
            for (int j = i + i; j < 2400000+20; j += i) {
                Prime[j] = true;
            }
        }
    }
}
vector<int> v;
int n;
int ans = -1;

void solve(int idx, int sum) {
    if (idx == n) {
        if (IsPrime(sum)) {
            ans = max(ans, sum);
        }
        return;
    }
    solve(idx + 1, sum + v[idx]);
    solve(idx + 1, sum);
}


void doWork() {

    // مكسل اكتب ركرجن
    // خلاص هكتبه
    cin >> n;
    v.resize(n);
    for (auto &i: v)cin >> i;
    int s=0;
    solve(0, s);
    cout << ans;

}

int32_t
main() {

    fast();
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        doWork();
        cout << el;
    }

}