#include<iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector> 
#include <map> 
using namespace std;
 
typedef vector <int> vi;
typedef vector <long long int> vll;
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
#define int ll 

template<typename... T>
void read(T&... args) {
    ((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) { //rvalue reference is new to C++ 
    ((cout << args << " "), ...);
}
 
void solve(){
    int a, b, k;

    read(a, b, k); 

    vi arr1(k),arr2(k);

    map<int,int> boys,girls;
    for(int i=0;i<k;i++)
        cin>>arr1[i];
    for(int i=0;i<k;i++)
        cin>>arr2[i];
    int ans = 0;
    for(int i=0;i<k;i++){
        int boy = arr1[i];
        int girl = arr2[i];
        int cnt1 = boys[boy];
        int cnt2 = girls[girl];
        ans = ans + i - cnt1 - cnt2;
        boys[boy]++;
        girls[girl]++;
    }
    cout<<ans<<'\n';
    

}
signed main() {
  FIO; 
  int t; 
  cin >> t; 
  while(t--){
     solve(); 
  }
   return 0; 
}