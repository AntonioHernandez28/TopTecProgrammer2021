#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iomanip>
#include <set>
#include <cstring>
#include <stack>
#include <sstream>
#include <queue>
#include <unordered_set>
#include <cstdlib>
using namespace std;
 
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef unordered_set<int, int> hsii; 
typedef unordered_map<int, int> hmii; 

#define endl "\n"
#define deb(x) cout << #x << " " << x << endl;
#define fo(i, n) for(i=0; i<n; i++)
#define Fo(i, k, n) for(i=k; i<n; i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define FF first
#define SS second
#define ll long long
#define ld long double
#define ull unsigned long long
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl; 
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) { //rvalue reference is new to C++ 
    ((cout << args << " "), ...);
}

int bPow(int a, int b){
    int res = 1;
    while(b) {
        if (b & 1ll) {
            res = 1ll * res * a % MOD;
        }
        b >>= 1;
        a = 1ll * a * a % MOD;
    }
    return res;
}
 
 
void solve() {
    ll x;
    cin >> x;
    ll num = cbrt(x);
    for (ll i = 1; i < num + 1; ++i) {
        ll temp =  i * i * i * 1ll;
        ll diff = x - temp;
        if(diff == 0)
            continue;
        ll j = cbrt(diff);
        if(j * j * j *1ll == diff){
            cout << "YES" << endl;
            return;
        }
 
    }
    cout << "NO" << endl;
}

int main() {
  FIO; 
  int t; 
  cin >> t; 
  while(t--){
     solve(); 
  }
   return 0; 
}