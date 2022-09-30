#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

#define FAST ios::sync_with_stdio(0), cin.tie(0)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,a,b) for(ll i=a;i>b;i--)
#define endl '\n'

const ll MAX = INT_MAX;
const ll MIN = INT_MIN;
const ll MOD = 1e9 + 7;

ll ceil(ll a, ll b) {
    return (a + b - 1) / b; 
}


void dfs(ll v, vector<ll>* adj, vector<bool>& visited, vector<ll>& hps, vector<ll>& level, vector<ll>& parent){
    visited[v] = true;

    for (auto x: adj[v]){
        if (x!=parent[v]){

            // back edge
            if (visited[x]){
                hps[v] = min(hps[v], level[x]);
                // cout << "FROM DFS: " << v << " " << (hps[v]) << " "  << level[x] << endl;
            }
            // forward edge
            else{
                level[x] = level[v] + 1;
                parent[x] = v;
                dfs(x, adj, visited, hps, level, parent);
                hps[v] = min(hps[v], hps[x]);
                // cout << "FROM DFS: " << v << " " << (hps[v]) << " "  << level[x] <<  endl;
            }
        }
    }
}

void solve(){
    ll n, m;
    cin >> n >> m;

    vi adj[n];

    while(m--){
        ll a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n, false);
    vector<ll> parent(n, -1);
    vector<ll> level(n, 0);
    vector<ll> hps(n, INT_MAX);


    // Approach 1: DP on High Points
    dfs(0, adj, visited, hps, level, parent);

    // Approach 2: DP on Edges Only


    // ll i = 0;
    // for (auto x: parent){
    //     cout << i << " " << x << " " << level[i] << " " << hps[i++] << endl;
    // }
    // cout << endl;

    rep(i,1,n){
        if (hps[i] > level[i]-1){
            cout << parent[i] << " " << i  << endl;
        }
    }


}


int main() {
    FAST;
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
