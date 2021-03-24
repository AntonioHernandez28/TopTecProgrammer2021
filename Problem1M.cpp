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
 
vi v, ans;
 
void dfs(int l, int r, int dep)
{
    if (l == r)
        ans[l] = dep;
    else
    {
        int mx = 0, mxp = -1;
        for (int i = l; i <= r; i++)
            if (v[i] > mx)
                mx = v[i], mxp = i;
 
        ans[mxp] = dep;
 
        if (mxp > l)
            dfs(l, mxp - 1, dep + 1);
        if (mxp < r)
            dfs(mxp + 1, r, dep + 1);
    }
}

void solve(){
    int n;
    cin >> n;
    v.resize(n + 1), ans.resize(n + 1);
 
    for (int i = 1; i <= n; i++) cin >> v[i];
    dfs(1, n, 0);
 
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
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