#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define ll                 long long
#define all(v)             v.begin(),v.end()
#define  el   "\n"
#define clr(v, val) memset(v,val,sizeof(v));
const ll mod = 1e9 + 7;
const ll OO = 0x3F3F3F3F;
const ll N = 1e6 + 10;


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

///-------------------Math Functions-------------------
ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

/// Prime
bool CheckIsPrime(long long n) {
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
ll FastPow(ll a, ll b) {
    ll res = 1; //  Time --> log (b)
    while (b) {
        if (b % 2)res = res * a;
        a = a * a;
        b /= 2;
    }
    return res;
}

/// Fast power with mod
long long FastPow_MOD(long long a, long long b, long long MOD) {
    long long res = 1; //  Time --> log (b)
    while (b) {
        if (b % 2)res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

/// divisors
vector<int> GetDivisors(int n) {
    vector<int> divisors;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (n / i != i)
                divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

/// check overflow
bool OverFlow(int a, int b) {
    long long x = a * b;
    if (x % b || x / b != a)return 1;
    return 0;
}

/// Prime Factors
vector<int> PrimeFactorization(long long n) {
    vector<int> factors;
    for (int i = 2; i * i <= sqrt(n); i += 2)
        while (n % i == 0) factors.push_back(i), n /= i;
    if (n > 1) factors.push_back(n);
    map<int, int> mp;/// Number of Prime factors= mp.size() & occurance of each prime factor
    for (auto i: factors)
        mp[i]++;
    return factors;
}

///-----------------Bitmask Functions--------------------

/// Update Bit to Zero
void SetBitOne(int &n, int k) {
    n = (n | (1LL << k));
}

/// Update Bit to One
void SetBitZero(int &n, int k) {
    n = (n & ~(1LL << k));
}

bool GetBit(int n, int k) {
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

int CountBit1(long long n) {
    int ones = 0;
    while (n) {
        ones++;
        n &= (n - 1); // delete first one bit and so on  O(number of one's)
    }
    return ones;//
}

string z;

void GetBinary(long long n) {
    if (n < 2) {
        z += '0' + n;
        return;
    }
    GetBinary(n / 2);
    z += n % 2 + '0';
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


int main() {
    int t = 1;
    while (t--) {

    }

}