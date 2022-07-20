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
    vector<pair<ll, ll>> seg;

    SGTree(ll n){
        seg.resize(4*n);
    }

    void build(ll index, ll low, ll high, vector<ll>& arr){

        if (low == high){
            seg[index].first = arr[low];
            seg[index].second = arr[low];
            return;
        }

        ll mid = low + (high-low)/2;

        build(2*index + 1, low, mid, arr);
        build(2*index + 2, mid+1, high, arr);

        seg[index].first = min(seg[2*index+1].first, seg[2*index+2].first);
        seg[index].second = seg[2*index+1].second + seg[2*index+2].second;
    }
    
    ll queryMin(ll index, ll low, ll high, ll left, ll right){
        // no overlap [low, high] [l, r] or [l, r][low, high]
        if (high < left || right < low){
            return INT_MAX;
        }

        // complete overlap: node's range lies completely in query range [left, low, high, right]
        if (left <= low && high <= right){
            return seg[index].first;
        }

        // partial overlaps
        ll mid = low + (high - low)/2;
        ll lans = queryMin(2*index+1, low, mid, left, right);
        ll rans = queryMin(2*index+2, mid+1, high, left, right);
        
        return min(lans, rans);

    }

    ll querySum(ll index, ll low, ll high, ll left, ll right){
        // no overlap [low, high] [l, r] or [l, r][low, high]
        if (high < left || right < low){
            return 0;
        }

        // complete overlap: node's range lies completely in query range [left, low, high, right]
        if (left <= low && high <= right){
            return seg[index].second;
        }

        // partial overlaps
        ll mid = low + (high - low)/2;
        ll lans = querySum(2*index+1, low, mid, left, right);
        ll rans = querySum(2*index+2, mid+1, high, left, right);
        
        return lans + rans;;

    }

    void update(ll index, ll low, ll high, ll indToUpdate, ll valToUpdate){
        if (low == high){
            seg[index].first = valToUpdate;
            seg[index].second = valToUpdate;
            return;
        }

        ll mid = low + (high - low)/2;
        if (indToUpdate <= mid) update(2*index+1, low, mid, indToUpdate, valToUpdate);
        if (indToUpdate > mid) update(2*index+2, mid+1, high, indToUpdate, valToUpdate);

        seg[index].first = min(seg[2*index+1].first, seg[2*index+2].first);
        seg[index].second = seg[2*index+1].second + seg[2*index+2].second;
    }



};


int main() {
    FAST;
    ll n, q;
    cin >> n >> q;
    vi a(n);
    rep(i,0,n){cin >> a[i];}
    SGTree s1(n);
    s1.build(0, 0, n-1, a);
    
    while(q--){
        ll l, r;
        cin >> l >> r;
        cout << s1.querySum(0, 0, n-1, l, r-1) << endl;
       
    }

    return 0;
}
