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
#define INF 1e18
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
 
void solve(){
      ll n,m;
      cin>>n>>m;
      vector <pair<ll,ll>> v(n);
      vector <ll> a,b;
      ll ans=INF;
      ll sum=0;
      for(int i=0;i<n;i++)cin>>v[i].FF;
        for(int i=0;i<n;i++){
            cin>>v[i].SS;
            sum+=v[i].FF;
            if(v[i].SS==1){
                a.pb(v[i].FF);
            }
            else b.pb(v[i].FF);
        }
 
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
 
        if(sum<m){
            cout<<-1<<endl;
            return;
        }
 
        sum=0;
        for(int i=0;i<a.size();i++){
            sum+=a[i];
            if(sum>=m){
            ans=min(ans,i+1ll);
        }
        }
        
        sum=0;
        for(int i=0;i<b.size();i++){
            sum+=b[i];
            if(sum>=m){
            ans=min(ans,2ll*(i+1));
        }
        }
        
 
        for(int i=1;i<a.size();i++){
            a[i]+=a[i-1];
        }
        for(int i=1;i<b.size();i++){
            b[i]+=b[i-1];
        }
 
        for(int i=0;i<b.size();i++){
            int x=lower_bound(a.begin(),a.end(),m-b[i])-a.begin();
            if(x<a.size()){
                ans=min(ans,2ll*(i+1) + (x+1));
            }
        }
 
        cout<<ans<<endl;
 
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