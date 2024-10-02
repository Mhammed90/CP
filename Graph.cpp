#include <bits/stdc++.h>

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
#define needForSpeed       ios::sync_with_stdio(false);cin.tie(NULL);
const int Mod = 1e9 + 7;
const int Oo = 0x3F3F3F3F;
const int N = 3e5 + 10;
const int Inf = 1e9 + 7;
//#define  int long long

ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int dx[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dy[] = {-1, 1, 0, 0, 1, 1, -1, -1};

int n, m;
vector<int> adj[N];
int vis[N];

///-----------------Cyclic In directed--------------
//// اروح لكل واحد و اقوله مين اللي ناداك
//// و اقوله متروحلوش
//// و لو فيه حد فيستد يبقي فيه سايكل
bool isCyclic(int u, int p) {
    vis[u] = true;
    for (int v: adj[u]) {
        if (vis[v] && p != v) {
            return true;
        } else if (!vis[v]) {
            if (isCyclic(v, u))return true;
        }
    }
    return false;
}

///-----------------Cycile In Undirected-----------
/// بروح اخليه inprograsee  و اشوف لو حد من ال cilde  بتوعي رجعلي و انا لسه inprogress  يبقي فيه سايكل
int notVisited = 0, visited = 1, inProgress = 2;

bool isCyclic(int u) {
    vis[u] = inProgress;
    for (int v: adj[u]) {
        if (vis[v] == inProgress) {
            return true;
        }
        if (vis[v] == notVisited)
            if (isCyclic(v))return true;
    }
    vis[u] = visited;
    return false;
}

///-----------------------BFS----------------

//////Shortest Path from source to distination
int dis[N];

void bfs(int src) {
    memset(dis, Oo, sizeof dis);
    dis[src] = 0;
    queue<int> q;
    q.push(src);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto v: adj[u]) {
            if (dis[v] == Oo)
                dis[v] = dis[u] + 1, q.push(v);
        }
    }
}

///-----------------------Bipartite-----------------------
/// if the Graph has odd Cycile it can't to be bipartite

int col[N], Red = 1, Blue = 2;

bool Bipartite(int u) {
    queue<int> q;
    q.push(u);
    col[u] = Red;
    while (q.size()) {
        u = q.front();
        q.pop();
        for (auto i: adj[u]) {
            if (col[i] == 0) {
                col[i] = (col[u] == Red ? Blue : Red);
                q.push(i);
            } else if (col[i] == col[u])
                return false;
        }
    }
    return true;
}

///----------------------TreeDiameter---------------
namespace TreeDiameter {
    vector<int> dis1(N), dis2(N);

    void bfs(int src, vector<int> &dis) {
        for (int i = 0; i <= n; i++)dis[i] = Oo;
        dis[src] = 0;
        queue<int> q;
        q.push(src);
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (auto v: adj[u]) {
                if (dis[v] == Oo)
                    dis[v] = dis[u] + 1, q.push(v);
            }
        }
    }

    int calc() {
        bfs(1, dis1);
        int mx = 0, node = 0;
        for (int i = 1; i <= n; i++) {
            if (mx < dis1[i])
                mx = dis1[i], node = i;
        }
        bfs(node, dis2);
        mx = 0, node = 0;
        for (int i = 1; i <= n; i++) {
            if (mx < dis2[i])
                mx = dis2[i], node = i;
        }
///        cout << node << "\n";
///        cout << dis2[node] << "\n";
        return dis2[node];
    }

};

///------------------dijkstra-----------------------

typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
int parent[N];
int n, m, src, en;
long long ans;
vector<vector<pii>> adj;
vector<long long> dis;

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    dis[src] = 0;
    while (pq.size()) {
        int node = pq.top().second;
        long long d = pq.top().first;
        pq.pop();
        if (d != dis[node])continue;
        for (auto v: adj[node]) {
            int to = v.first;
            long long len = v.second;
            if (dis[node] + len < dis[to]) {
                dis[to] = dis[node] + len;
                pq.push({dis[to], to});
                //    parent[to] = node;
            }
        }
    }

    //   ans = dis[en];

}

///------------------Bellmen Ford----------

struct Edge {
    int u, v, w;

    bool operator<(Edge const &other) {
        return w < other.w;
    }
};

int n, m, src;
vector<Edge> adj;
vector<int> path;
vector<long long> dis;

void BellmenFord() {
    // don't forget to resize the adjList with (m) number of edges
    // if done is true then there is a negative cycle
    // if dis[target] is Inf then there is no path
    /*
     copy this in solve  to resize

    dis.resize(n + 2, Inf);
    adj.resize(m);
    path.resize(n + 2, -1);

     */
    dis[src] = 0;

    bool done = true;
    for (int i = 0; i < n; i++) {
        done = false;
        for (Edge edge: adj)
            if (dis[edge.u] < Inf) {
                if (dis[edge.v] > dis[edge.u] + edge.w) {
                    dis[edge.v] = dis[edge.u] + edge.w;
                    // path[edge.v] = edge.u;
                    done = true;
                }
            }
        if (!done) {
            break;
        }
    }

}

///---------------------DSU----------------

struct DSU {
    vector<int> Parent, GroupSize;
    int numOfGroups;

    DSU(int n) {
        numOfGroups = n;
        Parent.resize(n + 2);
        GroupSize.resize(n + 2);
        for (int i = 0; i <= n; i++) {
            Parent[i] = i;
            GroupSize[i] = 1;
        }
    }

    int getParent(int u) {
        if (Parent[u] == u)
            return u;
        return Parent[u] = getParent(Parent[u]);
    }

    void merge(int u, int v) {
        int par1 = getParent(u);
        int par2 = getParent(v);
        if (par1 == par2) {
            return;
        }
        numOfGroups--;
        if (GroupSize[par1] > GroupSize[par2]) {
            Parent[par2] = par1;
            GroupSize[par1] += GroupSize[par2];
        } else {
            Parent[par1] = par2;
            GroupSize[par2] += GroupSize[par1];
        }
    }

    bool sameGroup(int u, int v) {
        int par1 = getParent(u);
        int par2 = getParent(v);
        return par2 == par1;
    }

    int getGroupSize(int u) {
        int par = getParent(u);
        return GroupSize[par];

    }
};

///---------------------Kruskal-----------------

void Kruskal() {
    cin >> n >> m;
    vector<Edge> ans, adj(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> adj[i].u >> adj[i].v >> adj[i].w;
    }
    ll cost = 0;
    sort(all(adj));
    DSU ds(n + 2);

    for (auto i: adj) {
        if (ds.getParent(i.u) != ds.getParent(i.v)) {
            cost += i.w;
            ans.push_back(i);
            ds.merge(i.u, i.v);
        }
    }
    // cout << cost << el;

    for (auto i: ans) {
        cout << i.u << " " << i.v << " " << i.w << el;

    }

}
///------------------------Prim's----------------
struct Edge {
    int v, w;
    Edge(int V = 0, int W = 0) {
        v = V;
        w = W;
    }
    bool operator<(const Edge &other) const {
        return w > other.w;
    }
};

int n, m;
vector<Edge> adj[N];
int cost;
bool Marked[N];


void Prim() {
    cost = 0;
    priority_queue<Edge> pq;
    pq.push(Edge(1, 0));
    memset(Marked, 0, sizeof Marked);
    while (pq.size()) {
        int u = pq.top().v;
        long long curCost = pq.top().w;

        pq.pop();
        if (Marked[u])continue;
        cout << u << " ";
        cost += curCost;
        Marked[u] = 1;
        for (auto edge: adj[u]) {
            if (!Marked[edge.v]) {
                pq.push(Edge(edge.v, edge.w));
            }
        }

    }

    cout << cost << el;

/*
 4 6
1 2 10
1 3 1
1 4 20
2 4 3
2 3 6
3 4 5

 */
}
///-----------------------------

int main() {

    int tc = 1;
    //cin >> tc;
    while (tc--) {

        cin >> n >> m;
        int st;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[v].push_back(u);
            adj[u].push_back(v);
            st = u;
        }


    }

}


