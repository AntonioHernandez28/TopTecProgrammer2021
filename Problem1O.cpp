#include<iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector> 
#include <map> 
using namespace std;
 
typedef long long int lli;
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
 
void solve(){
int n;
        cin>>n;
        map<lli,int>mp;
        for(int i=0;i<n;++i)
        {
            lli val;
            cin>>val;
            mp[val]++;
        }
        map<lli,int>::iterator it;
        vector<int>a;
        for(it=mp.begin();it!=mp.end();++it)
        {
            a.pb(it->SS);
        }
        n=a.size();
        lli sum=0;
        for(int i=0;i<n;++i)
        {
            sum+=a[i];
        }
        sort(all(a));
        lli pref[n];
        pref[0]=a[0];
        for(int i=1;i<n;++i)
        {
            pref[i]=pref[i-1];
            pref[i]+=a[i];
        }
        lli ans=sum;
        for(int i=0;i<n;++i)
        {
            lli r=pref[n-1];
            if(i>0)
                r-=pref[i-1];
            int cnt=n-i;
            lli t=(r-(1ll*a[i]*cnt));
            if(i>0)
                t+=pref[i-1];
            ans=min(ans,t);
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