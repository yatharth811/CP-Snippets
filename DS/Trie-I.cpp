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

// Trie Node
struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void put(char ch, Node* node){
       links[ch-'a'] = node; 
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }

};

class Trie{
    private:
        Node* root;

    public:

        Trie(){
            root = new Node();
        }

        void insert(string word){
            Node* node = root;
            for (int i = 0; i < word.length(); i++){
                if (!node->containsKey(word[i])){
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
            }

            node->setEnd();
        
        }

        bool search(string word){
            Node* node = root;
            for (int i = 0; i < word.length(); i++){
                if (!node->containsKey(word[i])){
                    return false;
                }
                node = node->get(word[i]);
            }

            return node->isEnd();

        }

        bool startsWith(string word){
            Node* node = root;
            for (int i=0; i < word.length(); i++){
                if (!node->containsKey(word[i])){
                    return false;
                }
                node = node->get(word[i]);
            }
            return true;
        }

};



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
