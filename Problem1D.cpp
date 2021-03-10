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
     int n;
        cin>>n;
        vi a(n);
        int k1 = 0, k2 = 0, k3 = 0, ans=0;
        for(int i = 0; i < n; ++i)
        {
            cin>>a[i];
            if(a[i] % 3 == 0) k1++;
            if(a[i] % 3 == 1) k2++;
            if(a[i] % 3 == 2) k3++;
        }
        if(k1 >= k2 && k1 >= k3 && !(k1 == k2 && k2 == k3))
        {
            int razn = abs(n / 3 - k1);
            ans+=razn;
            k1-=razn;
            k2+=razn;
        }
        if(k2 >= k1 && k2 >= k3 && !(k1 == k2 && k2 == k3))
        {
            int razn = abs(n / 3 - k2);
            ans+=razn;
            k2-=razn;
            k3+=razn;
        }
        if(k3 >= k2 && k3 >= k1 && !(k1 == k2 && k2 == k3))
        {
            int razn = abs(n / 3 - k3);
            ans+=razn;
            k3-=razn;
            k1+=razn;
        }
        if(k1 >= k2 && k1 >= k3 && !(k1 == k2 && k2 == k3))
        {
            int razn = abs(n / 3 - k1);
            ans+=razn;
            k1-=razn;
            k2+=razn;
        }
        if(k2 >= k1 && k2 >= k3 && !(k1 == k2 && k2 == k3))
        {
            int razn = abs(n / 3 - k2);
            ans+=razn;
            k2-=razn;
            k3+=razn;
        }
        if(k3 >= k2 && k3 >= k1 && !(k1 == k2 && k2 == k3))
        {
            int razn = abs(n / 3 - k3);
            ans+=razn;
            k3-=razn;
            k1+=razn;
        }
        if(k1 >= k2 && k1 >= k3 && !(k1 == k2 && k2 == k3))
        {
            int razn = abs(n / 3 - k1);
            ans+=razn;
            k1-=razn;
            k2+=razn;
        }
        if(k2 >= k1 && k2 >= k3 && !(k1 == k2 && k2 == k3))
        {
            int razn = abs(n / 3 - k2);
            ans+=razn;
            k2-=razn;
            k3+=razn;
        }
        if(k3 >= k2 && k3 >= k1 && !(k1 == k2 && k2 == k3))
        {
            int razn = abs(n / 3 - k3);
            ans+=razn;
            k3-=razn;
            k1+=razn;
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