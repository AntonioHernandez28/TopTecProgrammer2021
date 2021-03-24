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
#define fr(n)          for(ll i=0;i<n;i++)
#define pb push_back
#define make make_pair
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))  
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
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>>v;
     fr(m)
    {
        ll x,y;
        cin>>x>>y;
        v.pb(make(y,x));
    }
    if(m & 1)
    {    cout<<"NO"<<endl;
      return ;
    }
    
    
    SORT(v);
    for(ll i=1;i<m;i++)
    {
        if(v[i].FF==v[i-1].FF)
        {
            if(i%2==0)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    for(ll i=0;i<m;i+=2)
    {
        ll x1=v[i].SS;
        ll y1=v[i].FF;
 
        ll x2=v[i+1].SS;
        ll y2=v[i+1].FF;
 
        if(x1==x2)
        {  
            if ((y2-y1)%2==0)
            {
             cout<<"NO"<<endl;
             return ;
            }
            else
            {
                if(i+2 <m )
                {
                    if(v[i+2].FF==v[i+1].FF)
                    {
                        cout<<"NO"<<endl;
                        return ;
                    }
 
                }
 
            }
        }
        else
        {
            if(x1!=x2)
            {
                if((y2-y1)%2==1)
                {
                    cout<<"NO"<<endl;
                    return ;
                }
               
            }
        }
    }
 
    cout<<"YES"<<endl;
    return; 
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