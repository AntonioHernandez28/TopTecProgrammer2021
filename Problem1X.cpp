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

const char nl = '\n';
 
//int some_primes[10] = {100271, 500179, 1000003, 2000227, 5000321}
 
const int N = 2*100*1000 + 10 ;
 
void cal( int x , vi &a )
{
    int maxx = 0 ;
    for( int i = 2 ; i*i <= x ; i++ )
    {
        if( x % i == 0 )
        {
            maxx = max( maxx , a[ i ] ) ;
 
            if( i != x / i )
                maxx = max( maxx , a[ x / i ] ) ;
         }
    }
 
    a[ x ] += maxx ;
}
 
void solve(){
    int n ;
    cin >> n ;
 
    vi a( N , 0 ) ;
 
    for( int i = 0 ; i < n ; i++ )
    {
        int x ;
        cin >> x ;
 
        a[ x ]++ ;
    }
 
    for( int i = 2 ; i < N ; i++ )
    {
        if( a[ i ] > 0 )
            cal( i , a ) ;
    }
 
    int ans = *max_element( a.begin() + 2 , a.end() ) ;
    ans += a[ 1 ] ;
    ans = n - ans ;
 
    cout << ans << nl ;

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