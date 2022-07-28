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

// ll countChild(vector<ll>* adj, vector<ll>& c, ll x, ll p){
//     ll ans = 0;
//     for (auto y: adj[x]){
//         if (y!=p){
//             ans += 1 + countChild(adj, c, y, x);
//         }
//     }
//     return c[x]=ans;
// }

vector<vector<ll>> dp(1000001, vector<ll>(2, 0));

ll ans(vector<pair<ll, ll>>* adj, ll x, ll p){
    // ll bruh = 0;

    // if ()
    if (adj[x].size()==1 && adj[x][0].first==p) return 0;

    for (auto y: adj[x]){
        if (y.first!=p) dp[x][0] += ans(adj, y.first, x);
    }

    for (auto y: adj[x]){
        // ll te = 0;
        if (y.first!=p){
           dp[x][1] = max(dp[x][0] - ans(adj, y.first, x) + dp[y.first][0] + y.second, dp[x][1]);
        }
    }
    return max(dp[x][0], dp[x][1]);
}

void solve(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> adj[n];
    rep(i,1,n){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<ll> c(n);
    cout << ans(adj, 0, -1);
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
