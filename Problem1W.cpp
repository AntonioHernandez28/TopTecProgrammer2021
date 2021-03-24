#include<iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector> 
using namespace std;
 
const int N = 1000 + 9;
 
char s[N][N], t[N][N];
 
void solve(){
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%s", &s[i][1]);
    }
    for (int i = 1; i <= n; ++i){
        scanf("%s", &t[i][1]);
    }
    bool f = true;
    for (int i = 2; i <= n; ++i){
        int cnt = 0;
        for (int j = 1; j <= n; ++j){
            if ((s[i][j] ^ t[i][j]) != (s[i - 1][j] ^ t[i - 1][j])) ++cnt;
        }
        if (cnt != 0 && cnt != n){
            f = false; break;
        }
    }
    printf(f ? "YES\n" : "NO\n");
}
 
int main() {

  int t; 
  cin >> t; 
  while(t--){
     solve(); 
  }
   return 0; 
}