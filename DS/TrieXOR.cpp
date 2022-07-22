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

struct Node{
    Node* links[2];
    
    bool containsKey(int bit){
        // cout << bit << endl;
            return (links[bit]!=NULL);

        
        
    }
    
    void put(int bit){
        links[bit] = new Node();
    }
    
    Node* get(int bit){
        return links[bit];
    }
   
};

class Trie{
    private: 
        Node* root;
    
    public:

        Trie(){
            root = new Node();
        }


        void insert(int n){
            Node* node = root;
            for (int i=31; i>=0; i--){
                int bit = (n >> i) & 1;
                if (!node->containsKey(bit)){
                    node->put(bit);
                }
                node = node->get(bit);
            }
        }
        
        int getMax(int x){
            Node* node = root;
            int ans = 0;
            for (int i=31; i>=0; i--){
                int bit = (x >> i) & 1;
                if (node->containsKey(1-bit)){
                     node = node->get(1-bit);
                     ans = ans | (1 << i);
                }
                else{
                     node = node->get(bit);
                }
            
            }
            
            return ans;
            
        }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    // Write your code here
    Trie tr = Trie();
    for (auto x: arr1) tr.insert(x);
    int ans = 0;
    for (auto x: arr2){
        ans = max(tr.getMax(x), ans);
    }

    return ans;
   
}


void solve(){
    
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
