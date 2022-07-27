#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;

#define FAST ios::sync_with_stdio(0), cin.tie(0)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,a,b) for(ll i=a;i>b;i--)
#define endl '\n'


// To include policy based data structures
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// type, null, comparator, rb tree behind this ds
// using less_equal instead of less would make this multiset!


void solve(){
    ordered_set<int> A;

    // insertion
    A.insert(69);
    A.insert(42);
    A.insert(811);

    // finding kth element -> find_by_order (returns iterator) use dereferencing
    cout << *A.find_by_order(0) << endl;
    cout << *A.find_by_order(1) << endl;
    cout << *A.find_by_order(2) << endl;

    // finding number of elements smaller than x -> order_of_key
    cout << A.order_of_key(70) << endl;
    cout << A.order_of_key(7000) << endl;

    // lower bound and upper bound also available
    // when using less_equal instead of less, the lower and upper bound behave opposite
    cout << *A.lower_bound(69) << endl;
    cout << *A.upper_bound(69) << endl;

    // Remove elements
    A.erase(42);

    for (auto x: A){
        cout << x << " ";
    }
    cout << endl;

    

}


int main() {
    FAST;
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
