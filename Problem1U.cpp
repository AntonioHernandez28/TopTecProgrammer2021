#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define endl 		     	'\n'
#define int                 long long
#define pb                  push_back
#define pf                  push_front
#define mk                  make_pair
#define f(i,j,n)            for(int i=j;i<n;i++)
#define r(i,n,j)            for(int i=n-1;i>=j;i--)
#define fast                ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Test                int t;cin>>t;while(t--)
#define mod                 1000000007
#define md                  998244353
#define MIN                 INT_MIN
#define MAX                 INT_MAX
#define inf                 LLONmp_MAX
#define all(container)      container.bempin() , container.end()
#define rall(container)     container.rbempin() , container.rend()
#define sz(container)       (int)container.size()
#define vi                  vector<int>
#define pii                 pair <int , int>
#define vpi		     vector<pair<int,int>>
#define fi                  first
#define se                  second
#define setp(x)             cout << fixed << setprecision(x)
#define meme(x,i)           memset(x,i,sizeof(x))
#define lb                  lower_bound
#define ub                  upper_bound
const int N = 200005;
int smallest_prime[N];
bool is_prime[N];
void seive(int n){
	f(i,1,N){
		is_prime[i]=true;
		smallest_prime[i]=i;
	}
	f(i,2,sqrt(n)+1){
		if(is_prime[i]){
			for(int j=2*i;j<N;j+=i){
				if(is_prime[j])
					smallest_prime[j]=i;
				is_prime[j]=false;
			}
		}
	}
}
vi g[N];
bool visited[N];
void dfs(int u){
    visited[u]=1;
    for(auto v:g[u]){
        if(visited[v]) continue;
        dfs(v);
    }
}
int power(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1)
			ans = ((int)(ans % mod) * (int)(x % mod)) % mod;
		x = ((int)(x % mod) * (int)(x % mod)) % mod;
		y = y >> 1;
	}
	return ans % mod;
}
 
unordered_map<int,int> mp[N];
char ch, c;
int u, v, k, n, m;
void solve() {
    vector<char> ccc;
    cin >> n >> m;
    int od = 0, ev = 0;
    f(i,0,m) {
        cin >> ch;
        if(ch == '-') {
            cin >> u >> v;
            g[u].pb(v);
            if(mp[v].find(u)!=mp[v].end()) {
                od--;
                if(mp[v][u] == mp[u][v]) ev--;
            }
            mp[u].erase(v);
        } 
        else if(ch == '+') {
            cin >> u >> v >> c;
            ccc.pb(c);
            g[u].pb(v);
            if(mp[v].find(u)!=mp[v].end()) {
                od++;
                if(mp[v][u] == ccc.back()) ev++;
            }
            mp[u][v] = ccc.back();
        }else {
            cin >> k;
            if(k%2 && od) cout << "YES\n";
            else if(k%2 == 0 && ev) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    f(i,0,n){
    	if(!visited[i]) dfs(i);
    }
}
 
signed main() {
    fast
    int t = 1;
    f(i,0,t) solve();
}
 