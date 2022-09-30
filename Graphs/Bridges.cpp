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


void dfsHighPoints(ll v, vector<ll>* adj, vector<bool>& visited, vector<ll>& hps, vector<ll>& level, vector<ll>& parent){
    visited[v] = true;

    for (auto x: adj[v]){
        if (x!=parent[v]){

            // back edge
            if (visited[x]){
                hps[v] = min(hps[v], level[x]);
            }
            // forward edge
            else{
                level[x] = level[v] + 1;
                parent[x] = v;
                dfsHighPoints(x, adj, visited, hps, level, parent);
                hps[v] = min(hps[v], hps[x]);
            }
        }
    }
}


void dfsDp(ll v, vector<ll>* adj, vector<ll>& dp, vector<bool>& visited, vector<ll>& level, vector<ll>& parent){
    visited[v] = true;

    for (auto x: adj[v]){
        if (x!=parent[v]){

            if (visited[x]){
                // Back edge going up from v
                if (level[x] < level[v]){
                    dp[v]++;
                }
                // Back edge going down from v
                else{
                    dp[v]--;
                }
            }
            else{
                level[x] = level[v]+1;
                parent[x] = v;

                dfsDp(x, adj, dp, visited, level, parent);

                // Back edge going up from child of v
                dp[v] += dp[x];

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
    vector<ll> dp(n, 0);


    // Approach 1: DP on High Points
    dfsHighPoints(0, adj, visited, hps, level, parent);
    rep(i,1,n){
        if (hps[i] > level[i]-1){
            cout << parent[i] << " " << i  << endl;
        }
    }

    // Approach 2: DP on Edges Only
    // dp[u] = no of back edges going up from u + no of back edges going down from u - sigma dp[v] (v -> children of u)
    dfsDp(0, adj, dp, visited, level, parent);
    rep(i,1,n){
        if (!dp[i]){
            cout << parent[i] << " " << i << endl;
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
