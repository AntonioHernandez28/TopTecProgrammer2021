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

struct str {
    int size;
    int f;
    vector<int>sums;
    void init(int n)
    {
        size=1;
        while(size<n)size=size*2;
        sums.assign(2*size,0LL);
    }
    void set(int val,int i,int x,int lx,int rx)
    {
        if(rx-lx==1)
        {
            sums[x]=val;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m)
        {
            set(val,i,2*x+1,lx,m);
        }
        else
        {
            set(val,i,2*x+2,m,rx);
        }
        sums[x]=max(sums[2*x+1],sums[2*x+2]);
    }
    int one(int val,int x,int lx,int rx)
    {
        if(sums[x]<val) {
            if(x==0)
            {
                return -1;
            }
        }
        if((rx-lx)==1)
        {
            if(f==-1) {
                f = lx;
            }
        }
        else if(sums[2*x+1]>=val)
        {
            one(val,2*x+1,lx,(lx+rx)/2);
        }
        else
        {
            one(val,2*x+2,(lx+rx)/2,rx);
        }

        return -1; 
 
    }
};
 
void solve(){
int n,m;
    cin>>n>>m;
    int a[n],x[m];
    int b[n];
    int sum=0;
    str st;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        sum+=a[i];
        if(i==0){
            b[i]=a[i];
        }else{
            b[i]=b[i-1]+a[i];
        }
    }
    for (int i = 0; i < m; ++i) {
        cin>>x[i];
    }
    int pre=*max_element(b,b+n);
    st.init(n);
    for(int i=0;i<n;i++) {
        st.set(b[i], i, 0, 0, st.size);
    }
    for (int i = 0; i < m; ++i) {
        if(sum<=0&&x[i]>pre){
            cout<<"-1 ";
            continue;
        }
        int ans,steps=0;
        if(x[i]>pre){
            ans=x[i]-pre;
            steps=(ans+sum-1)/sum;
        }
        int left=x[i]-steps*sum;
        st.f=-1;
        st.one(left,0,0,st.size);
        cout<<st.f+steps*n<<" ";
    }
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