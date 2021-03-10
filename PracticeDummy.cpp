#include<iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector> 
#include <algorithm>
using namespace std;
 
typedef vector <int> vi;
typedef vector <long long> vll; 
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
    int n, i; 
    cin >> n; 
    vll nums;
    fo(i, n){
        long long current; 
        cin >> current; 
        nums.pb(current); 
    } 

    long long TotalSum = 0; 
    for(auto x:nums) TotalSum += x; 
    

    vector<vector<bool>> dp(n, vector<bool>(TotalSum + 1, false));
    fo(i, n) dp[i][0] = false;  

    //printArr(dp, n, TotalSum);

    sort(nums.begin(), nums.end()); 
    
    vll nuevoNums; 
    for(int i = 1; i < n; i++) nuevoNums.pb(nums[i]); 
    nums = nuevoNums; 

    n -= 1; 

    for(long long i = 0; i < n ; i++){
        for(long long j = 1; j <= TotalSum; j++){ 
            if(i == 0){
                if(j <= nums[i]) dp[i][j] = true; 
                else dp[i][j] = false;    
            }
            else{
                if(j <= nums[i]) dp[i][j] = true; 
                else dp[i][j] = dp[i - 1][j - nums[i]];     
            }
        } 
    }

    if(dp[n-1][TotalSum]) cout << "NO" << '\n'; 
    else cout << "YES" << '\n'; 
    
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