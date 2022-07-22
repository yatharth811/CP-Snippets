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
    Node* links[26];
    int prefixCount = 0;
    int wordCount = 0;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;        
    }
    
    void put(char ch){
        links[ch-'a'] = new Node();
    }
    
    Node* get(char ch){
        return links[ch-'a'];      
    }
    
    void setEnd(){
        wordCount++;
    }
    
    void increasePrefix(){
        prefixCount++;
    }
    
    void decreasePrefix(){
        prefixCount--;
        prefixCount = max(prefixCount, 0);
    }
    
    void decreaseWordCount(){
        wordCount--;
        wordCount = max(wordCount, 0);
    }
    
    int getEnd(){
        return wordCount;
    }
    
    int getPrefix(){
        return prefixCount;
    }
};

class Trie{
    private: 
        Node* root;
    
    public:

    Trie(){
    
        root = new Node();
    
    }

    void insert(string &word){
    
        Node* node = root;
        for (auto x: word){
           if (!node->containsKey(x)){
               node->put(x);
           }
           node = node->get(x);
           node->increasePrefix();
        }
        node->setEnd();
    }

    int countWordsEqualTo(string &word){
    
        Node* node = root;
        for (auto x: word){
           if (!node->containsKey(x)){
               return 0;
           }
           node = node->get(x);
           
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
    
        Node* node = root;
        for (auto x: word){
           if (!node->containsKey(x)){
               return 0;
           }
           node = node->get(x);
        }

        return node->getPrefix();
    
    }

    void erase(string &word){

        if (countWordsEqualTo(word) == 0) return;
        
        Node* node = root;
        for (auto x: word){
           node = node->get(x);
           node->decreasePrefix();
        }

        node->decreaseWordCount();

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
