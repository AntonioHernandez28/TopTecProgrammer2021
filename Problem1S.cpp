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

const int M=2e5+5;
ll a[M],b[M];
 
void solve(){
int n;
        int no=0,ne=0;
        ll suma=0,sumb=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            ll x;
            cin>>x;
            if(x&1){
                a[++no]=x;
            }
            else
                b[++ne]=x;
        }
        sort(a+1,a+1+no);
        sort(b+1,b+1+ne);
        for(int i=0;;i++){
            if(no==0&&ne==0) break;
            if(i&1){
                if(no==0)ne--;
                else if(ne==0) suma+=a[no--];
                else if(a[no]>b[ne]){
                    suma+=a[no--];
                }
                else{
                    ne--;
                }
            }
            else{
                if(ne==0) no--;
                else if(no==0) sumb+=b[ne--];
                else if(b[ne]>a[no]){
                    sumb+=b[ne--];
                }
                else
                    no--;
            }
        }
        ///cout<<suma<<" !!!"<<sumb<<endl;
        if(suma==sumb)cout<<"Tie"<<'\n';
        else if(suma<sumb)cout<<"Alice"<<'\n';
        else cout<<"Bob"<<'\n';
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