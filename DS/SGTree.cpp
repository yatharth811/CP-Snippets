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

class SGTree{
    public:
    vector<ll> seg;

    void build(ll index, ll low, ll high, vector<ll>& arr){

        if (low == high){
            seg[index] = arr[low];
            return;
        }

        ll mid = low + (high-low)/2;

        build(2*index + 1, low, mid, arr);
        build(2*index + 2, mid+1, high, arr);

        seg[index] = min(seg[2*index+1], seg[2*index+2]);

    }
    
    ll query(ll index, ll low, ll high, ll left, ll right){
        // no overlap [low, high] [l, r] or [l, r][low, high]
        if (high < left || right < low){
            return INT_MAX;
        }

        // complete overlap: node's range lies completely in query range [left, low, high, right]
        if (left <= low && high <= right){
            return seg[index];
        }

        // partial overlaps
        ll mid = low + (high - low)/2;
        ll lans = query(2*index+1, low, mid, left, right);
        ll rans = query(2*index+2, mid+1, high, left, right);
        
        return seg[index] = min(lans, rans);

    }

    void update(ll index, ll low, ll high, ll indToUpdate, ll valToUpdate){
        if (low == high){
            seg[index] = valToUpdate;
            return;
        }

        ll mid = low + (high - low)/2;
        if (indToUpdate <= mid) update(2*index+1, low, mid, indToUpdate, valToUpdate);
        if (indToUpdate > mid) update(2*index+2, mid+1, high, indToUpdate, valToUpdate);

        seg[index] = min(seg[2*index+1], seg[2*index+2]);

    }



};


int main() {
    FAST;
    ll t;
    // cin >> t;
    // while(t--){
        // solve();
        ll n, q;
        cin >> n;
        vi a(n);
        rep(i,0,n){cin >> a[i];}

        SGTree s1;
        s1.seg.resize(4*n);
        s1.build(0, 0, n-1, a);
        // cout << s1.query(0, 0, n-1, 1, 4) << endl;
        // s1.update(0, 0, n-1, 4, 13);
        // cout << s1.query(0, 0, n-1, 1, 4) << endl;
        
       
    // }
    return 0;
}
