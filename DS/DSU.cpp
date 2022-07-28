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

class DSU{
    private:
    vector<ll> parent, len; // union by size
    
    public:
    DSU(ll n){
        parent.resize(n);
        len.resize(n);
        rep(i, 0, n){
            parent[i] = i;
            len[i] = 1;
        }
    }

    ll find(ll x){
        if (parent[x] == x){return x;}
        return parent[x] = find(parent[x]);  // path compression
    }

    void unite(ll x, ll y){
        ll p1 = find(x), p2 = find(y);
        if (p1!=p2){
            if (len[p1] < len[p2]){
                swap(p1, p2);
            }
            parent[p2] = p1;
            len[p1] += len[p2];
        }
    }

    ll getSize(ll x){
        return len[x] = len[find(x)];
    }

};

void solve(){
    ll n;
    cin >> n;
    DSU dsu(n);
    cout << dsu.find(0) << endl;
    cout << dsu.find(1) << endl;
    dsu.unite(0, 1);
    cout << dsu.find(0) << endl;
    cout << dsu.find(1) << endl;
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
