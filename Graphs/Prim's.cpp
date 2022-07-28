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

ll prims(vector<vector<pair<ll, ll>>> &adj, ll root, vector<ll> &parent){
    ll n = adj.size();
    vector<bool> taken(n, false);
    vector<ll> wts(n, INT_MAX);
    parent[root] = root;
    wts[root] = 0;
    
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, root});

    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        taken[x.second] = true;

        for (auto e: adj[x.second]){
            ll u = e.first, v = e.second;
            if (!taken[e.first] && e.second < wts[e.first]){
                parent[e.first] = x.second;
                wts[e.first] = e.second;
                pq.push({e.second, e.first});
            }
        }

    }
    ll sum = 0;
    for (auto x: wts){sum += x;}

    return sum;
}


void solve(){
    ll n, m, src;
    cin >> n >> m >> src;
    vector<vector<pair<ll, ll>>> adj(n, vector<pair<ll, ll>>());
    while(m--){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vi parents(n);
    ll sum = 0;
    sum = prims(adj, src, parents);
    cout << sum << endl;
    for (auto x: parents){
        cout << x << " ";
    }
    cout << endl;
} 


int main() {
    FAST;
    ll t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
