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
#define int long long 

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
    cin >> n; 
    int ones = 0, twos = 0; 
    int i;
    int sum = 0;  
    fo(i, n){
        int current; 
        cin >> current; 
        sum += current; 
        if(current == 1) ones++; 
        else twos++; 
    }

   if((ones + (2*twos)) % 2 == 1) cout << "NO" << endl; 
   else{
       if(twos % 2 == 1 && ones == 0) cout << "NO" << endl; 
       else cout << "YES" << endl; 
   }
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