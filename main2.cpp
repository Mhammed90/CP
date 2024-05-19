#include <bits/stdc++.h>


using namespace std;
#define ll                 long long
#define all(v)             v.begin(),v.end()
#define  el   "\n"
#define clr(v, val) memset(v,val,sizeof(v));
const long long Mod = 1e9 + 7;
const ll OO = 0x3F3F3F3F;
const ll N = 1e6 + 10;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>  // find_by_order, order_of_key

int dx[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dy[] = {-1, 1, 0, 0, 1, 1, -1, -1};

void Fast_IO() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
//#ifndef ONLINE_JUDGE
//    freopen( "input.txt", "r",stdin);
//    freopen( "output.txt", "w",stdout);
//    freopen( "error.txt", "w",stderr);
//#endif
}

//SET A REALISTIC GOALS,AVOID OVER-EXPECTATIONS
struct Comp {
    bool operator()(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) const {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second.first < b.second.first;
    }
};

///-------------------Math Functions-------------------
ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

/// Prime
bool IsPrime(long long n) {
    if (n == 2)return true;
    if (!(n % 2) || n < 2)return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

/// Sieve Eratosthenes
void Sieve() {
    vector<bool> Prime((int) 1e6 + 10);
    Prime[0] = Prime[1] = true;
    for (int i = 2; i < 1e6 + 10; i++) {
        if (Prime[i] == 0) {
            for (int j = i + i; j < 1e6 + 10; j += i) {
                Prime[j] = true;
            }
        }
    }
}

/// smallest prime Factor and then find factors for the number
vector<int> SPF(int N) {
    vector<int> Spf(N);
    for (int i = 1; i < N; i++)
        Spf[i] = i;
    for (long long i = 2; i < N; i++) {
        if (Spf[i] != i)
            continue;
        for (long long j = i + i; j < N; j += i) {
            if (Spf[j] != j)
                continue;
            Spf[j] = i;
            // SPF[j]=min(SPF[j],(int)i);
        }
    }
    return Spf;
}

/// fast power
long long fastpo(long long a, long long b) {
    ll res = 1;
    while (b) {
        if (b % 2)res = res * a;
        a = a * 1LL * a * 1LL;
        b /= 2;
    }
    return res;
}

///////
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
///--------------------nCr------------
namespace nCr {
    long long fastpo(long long base, long long exp) {
        long long ans = 1;
        while (exp) {
            if (exp & 1) ans = (1LL * ans * base) % Mod;
            base = (1LL * base * base) % Mod;
            exp >>= 1;
        }
        return ans;
    }
    vector<long long> fac, inv, finv;

    void sz(int n) {
        fac.resize(n + 3), inv.resize(n + 3), finv.resize(n + 3);
        fac[0] = inv[0] = inv[1] = finv[0] = finv[1] = 1;
        for (int i(1); i <= n; ++i) fac[i] = fac[i - 1] * i % Mod;
        for (int i(2); i <= n; ++i) inv[i] = Mod - Mod / i * inv[Mod % i] % Mod;
        for (int i(2); i <= n; ++i) finv[i] = finv[i - 1] * inv[i] % Mod;
    }

    long long C(int n, int r) {
        if (n < 0 or r > n) return 0;
        return (fac[n] * finv[r] % Mod * finv[n - r] % Mod) % Mod;
    }
}

/// Fast power with mod
long long fastpoMod(long long base, long long exp) {
    long long ans = 1;
    while (exp) {
        if (exp & 1) ans = (1LL * ans * base) % Mod;
        base = (1LL * base * base) % Mod;
        exp >>= 1;
    }
    return ans%Mod;
}

/// divisors
vector<int> getDivisor(int n) {
    vector<int> divs;
    for (long long i = 1; i * i <= n; ++i)
        if (n % i == 0) {
            divs.push_back(i);
            if (n / i != i)divs.push_back(n / i);
        }
    sort(divs.begin(), divs.end());
    return divs;
}

/// check overflow
bool OverFlow(int a, int b) {
    long long x = a * b;
    if (x % b || x / b != a)return 1;
    return 0;
}

/// PrimeFactors
vector<ll> primeFactors(long long n) {
    vector<ll> factors;
    while (n % 2 == 0) factors.push_back(2), n /= 2;
    for (int i = 3; i * i <= n; i += 2)
        while (n % i == 0) factors.push_back(i), n /= i;
    if (n > 1) factors.push_back(n);
    map<ll, int> mp;
    for (auto i: factors)
        mp[i]++;
    return factors;
}

///-----------------Bitmask Functions--------------------

/// Update Bit to Zero
void setBitToOne(int &n, int k) {
    n = (n | (1LL << k));
}

/// Update Bit to One
void setBitToZero(int &n, int k) {
    n = (n & ~(1LL << k));
}

bool getBit(int n, int k) {
    return ((n >> k) & 1);
}

void Flip(long long &n, int k) {
    n = (1LL << k) ^ n;
}

bool IsPowerOfTwo(ll n) {
    return (n & (n - 1)) == 0;
}

void DeleteFirstOneBit(int &n) {
    n = (n & (n - 1));
}

int countBits(long long n) {
    int ones = 0;
    while (n) {
        ones++;
        n &= (n - 1); // delete first one bit and so on  O(number of one's)
    }
    return ones;
}



string getBinary(long long n) {
  string ret="";
    while (n)
    {
        ret+=('0'+(n&1));
        n>>=1;
    }
   // reverse(ret.begin(),ret.end());
    return ret;
}

long long FirstBitValue(long long n) {
//    return n & ~(n - 1);
//    // or
    return (n | (n - 1)) - (n - 1);
}

/// DSU Union Find
int parent[(int) 1e5 + 5];

void init(int N) {
    for (int i = 1; i < N; i++) {
        parent[i] = i;
    }
}

int getParent(int u) {
    if (u == parent[u])
        return u;
    return parent[u] = getParent(parent[u]);// Path Compression
}

void makeFriend(int u, int v) {
    u = getParent(u);
    v = getParent(v);
    parent[u] = v;
}

bool areFriends(int u, int v) {
    return getParent(u) == getParent(v);
}


//--------------DP---------------

int LIS() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = nums.size();
    vector<int> dp(n);
    LIS[0] = 1;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j])mx = max(mx, dp[j]);
        }
        dp[i] = mx + 1;
        ans = max(dp[i], ans);
    }
    return ans;
}

//////////// Dynamic Programming/////////////
///-----------Knapsack Problem ------------

int n, val;
vector<pair<int, int>> v;
int dp[(int) 2e4 + 100][(int) 2e4];

int solve(int idx, int remin) {
    if (idx >= n)return 0;
    int &ret = dp[idx][remin];
    if (~ret)return ret;
    if (remin - v[idx].first >= 0) {
        ret = v[idx].second + solve(idx + 1, remin - v[idx].first);
    }
    return ret = max(ret, solve(idx + 1, remin));
}

//////////LCS/////////////


int dp[1001][1001];
string a, b;
int n, m;

int LCS(int i, int j) {
    if (i == n || j == m)
        return 0;
    int &ret = dp[i][j];
    if (~ret)return ret;
    ret = 0;
    if (a[i] == b[j]) {
        return ret = LCS(i + 1, j + 1) + 1;
    }

    ret += max(LCS(i, j + 1), LCS(i + 1, j));
    return ret;
}

/////////LIS/////////////////


int dp[3001][3001];
vector<int> v;
int n, m;

int LIS(int i, int prev) {
    if (i == n)
        return 0;
    int &ret = dp[i][prev];
    if (~ret)return ret;

    int op1 = LIS(i + 1, prev);// leave
    int op2 = 0;
    if (prev == n || v[i] > v[prev]) //pick
        op2 = LIS(i + 1, i) + 1;
    ret = max(op2, op1);
    return ret;


    // ret=max(LIS(i+1,prev),(prev==n||v[i]>v[prev]?LIS(i+1,i)+1:0));
    return ret;
}


int main() {
    int t = 1;
    while (t--) {

    }

}

