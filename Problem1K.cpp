#include <iostream> 
#include <vector>
#include <map> 
using  namespace std;
#define fast {ios_base::sync_with_stdio(false); cin.tie(0);}
typedef long long ll;
 
ll call(vector<ll>&a,vector<ll>&b){
    map<ll,bool>mp;ll ans=0,val;
    for(auto x:a) mp[x]=1;
    for(auto x:b) if(mp[x]) ans++;ll c=ans;
    for(auto x:b){
       if(mp[x]) c--;
       val=upper_bound(a.begin(),a.end(),x)-a.begin();
       val=upper_bound(b.begin(),b.end(),x)-
            upper_bound(b.begin(),b.end(),x-val);
       ans=max(ans,c+val);
    }return ans;
}
 
int main()
{
    ll i,j,k,n,m,c,t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<ll>al,ar,bl,br;
        for(i=0;i<n;i++){ cin>>k;
            if(k>0) ar.push_back(k);
            else al.push_back(-k);
        }for(i=0;i<m;i++){ cin>>k;
            if(k>0) br.push_back(k);
            else bl.push_back(-k);
        }sort(bl.begin(),bl.end());
        sort(al.begin(),al.end());
        cout<<call(al,bl)+call(ar,br)<<"\n";
    }
}