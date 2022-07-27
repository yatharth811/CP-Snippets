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

// dsp -> djikstra's shortest path
void dsp(vector<vector<pair<ll,ll>>> &adj, ll src, vector<ll> &distance){
    ll n = adj.size();
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    vector<bool> visited(n, false);
    distance[src] = 0;
    q.push({0, src});

    while(!q.empty()){
        auto x = q.top();
        q.pop();
        if (visited[x.second]) continue;
        visited[x.second] = true;

        for (auto y: adj[x.second]){
            if (distance[x.second] + y.second < distance[y.first]){
                distance[y.first] = distance[x.second] + y.second;
                q.push({distance[y.first], y.first});
            }
        }
    }

}

void solve(){
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n, vector<pair<ll, ll>>());

    while(m--){
        ll a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].push_back({b, w});
    }  

    ll x, y;
    cin >> x >> y;
    x--; y--;

    vector<ll> distance(n, INT_MAX);

    dsp(adj, x, distance);

    cout << distance[y] << endl;

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
