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
int n;
int ans[200001], arr[200001];
 
int score(int j) {
	if (j + arr[j] > n) {
		return arr[j];
	} else {
		return ans[j + arr[j]] + arr[j];
	}
}
 
void solve(){
    cin>>n;
		for (int i=1; i<=n; i++) {
			cin>>arr[i];
		}
		for (int i=n; i>=1; i--) {
			ans[i] = score(i);
		}
		int maxx = 0;
		for (int i=1; i<=n; i++) {
			if (ans[i] > maxx) {
				maxx = ans[i];
			}
		}
		cout<<maxx<<endl;

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