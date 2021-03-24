#include<iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector> 
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

bool can_win(int v[], int n, int idx) {
    ll s = v[idx];
    for (int i = 0; i < n; i++) {
        if (i == idx) continue;
        if (s < v[i]) return false;
        s += v[i];
    }
    return true;
}

 
void solve(){
        int n;
    cin >> n;
 
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
 
    int b[n];
    copy(a, a+n, b);
    sort(b, b+n);
 
    int l = 0, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (can_win(b, n, m)) {
            r = m;
        }
        else {
            l = m+1;
        }
    }
 
    vector<int> w;
    for (int i = 0; i < n; i++) {
        if (a[i] >= b[l]) {
            w.push_back(i+1);
        }
    }
 
    cout << w.size() << "\n";
    for (auto &x : w) cout << x << " ";
    cout << "\n";
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