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


///-----------------Bitmask Functions--------------------


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

