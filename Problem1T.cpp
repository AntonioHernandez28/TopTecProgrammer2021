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
 
void solve(){
    int
int n;cin>>n;
        vector<pair<pair<ll,ll>,ll>>ok(n);
        vector<pair<ll,ll>>jj(n+1);
        ll indices[n];
        fo(i,n){
            indices[i]=-1;
            ll h,w;
            cin>>h>>w;
            ok[i]={{-1*min(h,w),-1*max(h,w)},i+1};
        }
        sort(all(ok));
        jj[n]={-1000000000,0};
        fo(i,n){
            if(ok[n-i-1].f.se>jj[n-i].f){
                jj[n-i-1]={ok[n-i-1].f.se,ok[n-i-1].se};
            }
            else{jj[n-i-1]=jj[n-i];}
            //cout<<jj[n-i-1].f<<" "<<jj[n-i-1].se<<endl;
        }
        fo(i,n){
            //binary search so that min is just greater. Let h be the obtained index
            ll h=i+1;
            ll max=n-1;
            while(h<max){
                ll mid=(h+max)/2;
                if(ok[mid].f.f>ok[i].f.f){max=mid;}
                else{h=mid+1;}
            }
            if(h<n){
                if(ok[h].f.f>ok[i].f.f && jj[h].f>ok[i].f.se){
                indices[ok[i].se-1]=jj[h].se;
            }
            }
            //if(i==2){cout<<indices[ok[i].se-1]<<endl;}
        }
        fo(i,n){cout<<indices[i]<<" ";}
        cout<<endl;
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