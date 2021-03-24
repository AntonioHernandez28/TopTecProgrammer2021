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

int power(ll x,int n){
  ll ans=1;
  int mod=1000000007;
  x%=mod;
  while(n!=0){
    if(n&1){
      ans*=x;
      ans%=mod;
    }
    x*=x;
    x%=mod;
    n=n>>1;
  }
 
  return int(ans);
}

int nCr(int n,int r){
  int mod=1000000007;
  std::vector<ll> v(n+1,1);
  for(int i=2;i<=n;i++){
    v[i]=i*v[i-1];
    v[i]%=mod;
  }
 
  ll ans=1;
  ans = ((v[n]%mod)*(power(v[r]*v[n-r],mod-2)%mod))%mod;
 
 
  return int(ans);
}

bool comp(int x,int y){
  return x>y;
}
 
void solve(){
int n,k,i;
  cin>>n>>k;
  vi v(n);
 
  fo(i,n){
    cin>>v[i];
  }
 
  sort(v.begin(),v.end(),comp);
 
  int fav=v[k-1];
  int n1=0,r=0;
 
  fo(i,n){
    if(v[i]==fav&&i<k){
      r++;
    }
 
    if(v[i]==fav)
      n1++;
  }
 
 
  int ans=nCr(n1,r);
 
  cout<<ans<<endl;
  return ;
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